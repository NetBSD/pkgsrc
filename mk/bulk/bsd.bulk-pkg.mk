#	$NetBSD: bsd.bulk-pkg.mk,v 1.80 2005/05/06 00:52:30 rillig Exp $

#
# Copyright (c) 1999, 2000 Hubert Feyrer <hubertf@NetBSD.org>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#      This product includes software developed by Hubert Feyrer for
#	the NetBSD Project.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

##
## For this to work, put
##   DEPENDS_TARGET=	bulk-install
##   BATCH=		yes
## into your /etc/mk.conf, then cd /usr/pkgsrc; make bulk-package
##
## bulk-install will only compile pkgs if necessary, and install binary
##	pkgs if possible/available.
## bulk-package will build binary packages, and remove them (together with
##	any depending packages) immediately after that, leaving only the
##	binary package back. Broken packages are marked (``.broken'').
##

LS?=	ls
WC?=	wc
TO_HTML?=	${SED} -e 's,&,\&amp;,g' -e 's,<,\&lt;,g' -e 's,>,\&gt;,g'

# A sort(1) capable of very long lines is needed for full builds in "tflat".
# Some platforms (namely, Interix) may not provide one, so override here.
.if ${OPSYS} == "Interix"
_SORT=			${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}sort
.endif
_SORT?=			${SORT}

# This variable is set to 'yes' by the pkgsrc/mk/bulk/build script.  It enables
# the use of several cache files (DEPENDSTREEFILE, DEPENDSFILE, SUPPORTSFILE,
# and INDEXFILE) for speeding up the processing of dependencies.  If we're not
# actively in the middle of a bulk build, however, we don't know that these files
# exist or are up to date and they take quite a while to rebuild.  So unless
# they're known to exist and be up to date, don't use them.
USE_BULK_CACHE?=	no

# This variable may be set to 'no' to avoid automatic rebuilding of dependent
# packages based solely on timestamps of the package's pkgsrc files and/or
# its dependency binary packages.  This will cause rebuilding only when the
# full version number of the package changes (e.g., via PKGREVISION bump).
USE_BULK_TIMESTAMPS?=	yes

# Shall we remove any packages which are installed, but not required
# to build this package
PRECLEAN?=	yes

# If OBJHOSTNAME is set, use first component of hostname in cache and log files
# If OBJMACHINE is set, use ${MACHINE_ARCH} in the cache and log files
.if defined(OBJHOSTNAME)
.  if !defined(_HOSTNAME)
_HOSTNAME!= ${UNAME} -n
.  endif
BULK_ID?=	.${_HOSTNAME:C|\..*||}
.elif defined(OBJMACHINE)
BULK_ID?=	.${MACHINE_ARCH}
.else
BULK_ID?=
.endif

# This file exists to mark a package as broken
BROKENFILE?=	.broken${BULK_ID}.html

# This file is the work log for a broken package
BROKENWRKLOG?=	.broken${BULK_ID}.work.html

# This file is where the log of the build goes
BUILDLOG?=	.make${BULK_ID}

# This is the directory in which bulk build global files should be kept.
# It defaults to ${PKGSRCDIR}, but may be better suited to another directory
# if pkgsrc is on a remote (e.g., nfs) filesystem.
BULKFILESDIR?=	${PKGSRCDIR}

# This is a top level file which lists the entire pkgsrc depends tree in the
# format:
# foo/bar devel/libfoo
# meaning 'foo/bar' is requied to build 'devel/libfoo'
# this is in the format needed by tsort(1)
DEPENDSTREEFILE?=	${BULKFILESDIR}/.dependstree${BULK_ID}

# This is a top level file which lists the entire pkgsrc depends tree in the
# format:
# foo/bar depends on: devel/libfoo devel/libbar devel/baz .....
# ie, to build foo/bar we need devel/libfoo devel/libbar devel/baz ... installed
DEPENDSFILE?=	${BULKFILESDIR}/.depends${BULK_ID}

# This is a top level file which lists the entire pkgsrc depends tree in the
# format:
# devel/libfoo is depended upon by: foo/bar graphics/gtkfoo ...
# ie, to build foo/bar we need devel/libfoo to be installed.
#     to build graphics/gtkfoo we need devel/libfoo to be installed
SUPPORTSFILE?=	${BULKFILESDIR}/.supports${BULK_ID}

# This is a top level file which cross-references each package name and pkg
# directory in the format:
# devel/libfoo libfoo-1.3
INDEXFILE?=	${BULKFILESDIR}/.index${BULK_ID}

# File containing a list of all the packages in the correct order for a bulk
# build.  The correct order is one where packages that are required by others
# are built before the packages which require them.
ORDERFILE?=	${BULKFILESDIR}/.order${BULK_ID}

# File which is used as a timestamp for when the build started.  This is used
# eventually for looking for leftover files (files not properly deinstalled)
STARTFILE?=	${BULKFILESDIR}/.start${BULK_ID}

# File created and used by lintpkgsrc(8) to cache package metadata for
# pruning and bulk-upload exclusions.
LINTPKGSRC_DB?=	${BULKFILESDIR}/.lintpkgsrc.db${BULK_ID}

# File which is used as a database for bulk builds in which SPECIFIC_PKGS is
# defined.  This database is used to hold all the dependency and index
# information for the specific packages as well as their dependencies.  In a
# SPECIFIC_PKGS bulk build, this file is created and then used to create the
# INDEXFILE and DEPENDSTREEFILE.
BULK_DBFILE?=	${BULKFILESDIR}/.bulk_db${BULK_ID}

# A list of pkgs which we should _never_ delete during a build.  The primary
# use is for digest and also for xpkgwedge.  Add pkgtools/xpkgwedge in
# /etc/mk.conf to do an xpkgwedged bulk build.
BULK_PREREQ+=		pkgtools/digest

# by default, clean up any broken packages
_PRESERVE_WRKDIR?=	no

# create an escaped version of PKGPATH.  We do this because
# in several places we want to be able to use something like
# foo/bar.baz++ in a regular expression but have it be interpreted
# literally.  So, turn it into foo\/bar\.baz\+\+
_ESCPKGPATH=	${PKGPATH:C@\/@\\/@g:C@\+@\\+@g:C@\.@\\.@g:Q}

# build the cache files used as part of a full bulk build
# Note:  we have to install the BULK_PREREQ packages _before_
# extracting the depends tree because some packages like
# xpkgwedge only become DEPENDS if it is installed
bulk-cache:
	@${ECHO_MSG} "BULK> Installing BULK_PREREQ packages"
.for __prereq in ${BULK_PREREQ}
	cd ${PKGSRCDIR}/${__prereq} && ${MAKE} bulk-install
.endfor
	${RM} -f ${BULK_DBFILE}
	${TOUCH} ${BULK_DBFILE}
.if !defined(SPECIFIC_PKGS)
	@${ECHO} "This file is unused for a full pkgsrc bulk build" >> ${BULK_DBFILE}
	@${ECHO} "It is only used for a SPECIFIC_PKGS bulk build" >> ${BULK_DBFILE}
	@${ECHO_MSG} "BULK> Building complete pkgsrc dependency tree (this may take a while)."
	cd ${PKGSRCDIR} && ${SETENV} BMAKE=${MAKE} ${SH} mk/bulk/printdepends ${BROKENFILE} > ${DEPENDSTREEFILE}
	@${ECHO_MSG} "BULK> Generating package name <=> package directory cross reference file"
	@${ECHO_MSG} "      (this may take a while)."
	cd ${PKGSRCDIR} && ${SETENV} BMAKE=${MAKE} ${SH} mk/bulk/printindex ${BROKENFILE} > ${INDEXFILE}
.else
	@${ECHO_MSG} "BULK> Extracting database for SPECIFIC_PKGS subset of pkgsrc"
	@${ECHO_MSG} "      along with their dependencies"
.for __tmp__ in ${SUBDIR} ${BULK_PREREQ} ${PERL5_PKGSRCDIR:C|.*/([^/]*/[^/]*)$|\1|} pkgtools/pkglint
	cd ${PKGSRCDIR}/${__tmp__} && ${SETENV} BMAKE=${MAKE} AWK=${AWK} EXPR=${EXPR} ${SH} ../../mk/scripts/mkdatabase -a -f ${BULK_DBFILE}
.endfor
	@${ECHO_MSG} "BULK> Extracting dependency tree file"
	${AWK} '/^(build_)?depends/ {pkgs[$$2] = 1; cat=$$2; sub(/\/.*/, "", cat); \
		for(i=3; i<=NF; i=i+1){ \
			listed[$$2] = 1; \
			sub(/[^:]*:\.\.\/\.\.\//, "", $$i); \
			sub(/[^:]*:\.\./, cat , $$i); \
			print $$i " " $$2; \
		}} END{ \
		for(pkg in pkgs) {if( pkg in listed ) {} else{ print pkg " " pkg;}} \
		}' \
		${BULK_DBFILE} | ${_SORT} -u > ${DEPENDSTREEFILE}
	@${ECHO_MSG} "BULK> Extracting package name <=> package directory cross reference file"
	${AWK} '/^index/ {print $$2 " " $$3 " "}' ${BULK_DBFILE} > ${INDEXFILE}
.endif
	@${ECHO_MSG} "BULK> Sorting build order."
	${TSORT} ${DEPENDSTREEFILE} > ${ORDERFILE}
	@${ECHO_MSG} "BULK> Generating up and down dependency files."
	${SETENV} SORT=${_SORT:Q} ${AWK} -f ${PKGSRCDIR}/mk/bulk/tflat up ${DEPENDSTREEFILE} > ${SUPPORTSFILE}
	${SETENV} SORT=${_SORT:Q} ${AWK} -f ${PKGSRCDIR}/mk/bulk/tflat down ${DEPENDSTREEFILE} > ${DEPENDSFILE}

# remove the bulk cache files
clean-bulk-cache:
	${RM} -f ${BULK_DBFILE} \
		${DEPENDSTREEFILE} \
		${DEPENDSFILE} \
		${SUPPORTSFILE} \
		${INDEXFILE} \
		${ORDERFILE}

# check if the $REF file is uptodate, i.e. is newer than any of
# the pkg files; prints "1" if upto date, "0" if not.
bulk-check-uptodate:
	@uptodate=1; \
	if [ -f "${REF}" ]; then \
		if [ "${REF:T}" != "${PKGFILE:T}" ]; then \
			${ECHO_MSG} >&2 "BULK> ${REF} is out of date (new version ${PKGNAME}); rebuilding..."; \
			uptodate=0; \
		elif [ "${USE_BULK_TIMESTAMPS}" = "yes" ]; then \
			${SHCOMMENT} "Check files of this package"; \
			newfiles="`${FIND} . -type f -newer "${REF}" -print | ${EGREP} -v -e ./work -e COMMENT -e DESCR -e README.html -e CVS -e '^\./\.' || ${TRUE}`"; \
			nnewfiles="`${FIND} . -type f -newer "${REF}" -print | ${EGREP} -v -e ./work -e COMMENT -e DESCR -e README.html -e CVS -e '^\./\.' | ${WC} -l`"; \
			if [ "$$nnewfiles" -gt 0 ]; then \
				${ECHO_MSG} >&2 "BULK> Package ${PKGNAME} ($$newfiles) modified since last 'make package' re-packaging..."; \
				uptodate=0; \
			else \
				${ECHO_MSG} >&2 "BULK> ${REF} is up to date."; \
			fi; \
		else \
			${ECHO_MSG} >&2 "BULK> ${REF} is up to date."; \
		fi; \
	else \
		${ECHO_MSG} >&2 "BULK> Package ${PKGNAME} not built yet, packaging..."; \
		uptodate=0; \
	fi; \
	if [ "$$uptodate" = "1" ]; then \
		${SHCOMMENT} "Check required binary packages"; \
		(${DEPENDS:C/:.*$//:@d@${ECHO} ${d:Q};@} ${TRUE}) | \
		(while read dep; do \
			${SHCOMMENT} "check against the binary pkg that pkg_add would pick, too:"; \
			${SHCOMMENT} "(Only one should be returned here, really...)"; \
			pkg=`${PKG_ADMIN} lsbest "${PACKAGES}/All/$$dep"`; \
			if [ -z "$$pkg" ]; then \
				${ECHO_MSG} >&2 "BULK> Required binary package $$dep does not exist, rebuilding..."; \
				exit 1; \
			elif [ "${USE_BULK_TIMESTAMPS}" = "yes" ] && [ -n "`${FIND} $$pkg -prune -newer ${REF} -print`" ]; then \
				${ECHO_MSG} >&2 "BULK> Required binary package $$dep (`basename $$pkg`) is newer, rebuilding..."; \
				exit 1; \
			else \
				${ECHO_MSG} >&2 "BULK> Required binary package $$dep (`basename $$pkg`) is usable."; \
			fi; \
		done) || uptodate=0; \
	fi; \
	${ECHO_MSG} $$uptodate

# rebuild binpkg if any of the pkg files is newer than the binary archive
# set DO to ":" to not actually do anything (debugging, ...)
bulk-package:
	@if [ -f ${BROKENFILE} ]; then \
		${ECHO_MSG} "BULK> *** Package ${PKGNAME} seems broken and needs attention:" ; \
		${LS} -la ${BROKENFILE}; \
		exit 1; \
	fi
	@( \
	if [ "${PRECLEAN}" = "yes" ]; then \
		${ECHO_MSG} '<pre>' ; \
		${ECHO_MSG} '' ; \
		${ECHO_MSG} '###' ; \
		${ECHO_MSG} '###' `date`: ; \
		${ECHO_MSG} '### ${MAKE} ${.TARGET} for ${PKGNAME}' ; \
		${ECHO_MSG} '### Current pkg count: ' `${LS} -l ${PKG_DBDIR} | ${GREP} '^d' | ${WC} -l` installed packages: `${LS} ${PKG_DBDIR} | ${GREP} -v pkgdb.byfile.db`; \
		${ECHO_MSG} '###' ; \
	fi \
	) 2>&1 | ${TEE} -a ${BUILDLOG}
	@uptodate=`${MAKE} ${MAKEFLAGS} bulk-check-uptodate REF=${PKGFILE}` ; \
	if ${PKG_INFO} -qe "${PKGNAME:C/-[^-]*$/-[0-9]*/}" ; then \
		installed=1; \
	else \
		installed=0; \
	fi ; \
	if [ $$uptodate = 1 ]; then \
		( if [ $$installed = 1 ]; then \
			${ECHO_MSG} "BULK> Package ${PKGNAME} is upto-date, and still installed" ; \
		else \
			${ECHO_MSG} "BULK> Nothing to be done." ; \
		fi \
		) 2>&1 | ${TEE} -a ${BUILDLOG}; \
	else \
		( if [ $$installed = 1 ]; then \
			${ECHO_MSG} "BULK> Removing outdated (installed) package ${PKGNAME} first." ; \
			${ECHO_MSG} ${MAKE} deinstall ; \
			${DO}       ${MAKE} deinstall ; \
			if ${PKG_INFO} -qe ${PKGWILDCARD} ; then \
				${ECHO_MSG} ${PKG_DELETE} -r ${PKGWILDCARD} ;\
				${DO} ${PKG_DELETE} -r ${PKGWILDCARD} ;\
			fi ;\
		fi ; \
		if [ -f ${PKGFILE} ]; then \
			${ECHO_MSG} "BULK> Removing old binary package..." ; \
			${ECHO_MSG} ${RM} -f ${PKGFILE} ; \
			${DO}       ${RM} -f ${PKGFILE} ; \
			for cat in ${CATEGORIES} ;\
			do \
				${ECHO_MSG} ${RM} -f ${PACKAGES}/$$cat/${PKGNAME}${PKG_SUFX}; \
				${DO} ${RM} -f ${PACKAGES}/$$cat/${PKGNAME}${PKG_SUFX}; \
			done ;\
		fi; \
		${ECHO_MSG} "BULK> Full rebuild in progress..." ; \
		${ECHO_MSG} "BULK> Cleaning package ${PKGNAME} and pre-requisite packages" ;\
		if [ "${USE_BULK_CACHE}" = "yes" ]; then \
			for pkgdir in ${PKGPATH} `${SED} -n -e "/^${_ESCPKGPATH} / s;^[^:]*:;;p" ${DEPENDSFILE}`; do \
				${DO}       (cd ${PKGSRCDIR}/$$pkgdir && ${MAKE} clean) ; \
			done ;\
		else \
			${ECHO_MSG} ${MAKE} clean CLEANDEPENDS=YES;\
			${DO} ${MAKE} clean CLEANDEPENDS=YES;\
		fi; \
		if [ "${PRECLEAN}" = "yes" ]; then \
			${ECHO_MSG} "BULK> Removing installed packages which are not needed to build ${PKGNAME}" ; \
			for pkgname in `${PKG_INFO} -e \*` ; \
			do \
				if [ "${USE_BULK_CACHE}" = "yes" ]; then \
					pkgdir=`${GREP} " $$pkgname " ${INDEXFILE} | ${AWK} '{print $$1}'` ;\
					if [ -z "$$pkgdir" ]; then \
					    pkgdir=unknown ; \
					fi; \
					if ${PKG_INFO} -qe $$pkgname ; then \
						${SHCOMMENT} "Remove only unneeded pkgs" ; \
						pkgdir2=`${ECHO} "$$pkgdir" | ${AWK} '{gsub(/\//,"\\\\/"); gsub(/\+/,"\\\\+"); gsub(/ /,"\\\\ "); gsub(/\./,"\\\\."); print}'` ; \
						tmp=`${SED} -n -e "/^${_ESCPKGPATH} .* $$pkgdir2 / s;.*;yes;p" ${DEPENDSFILE}` ; \
						if test "X$$tmp" = "Xyes" ; then \
							${ECHO_MSG} "BULK> ${PKGNAME} requires installed package $$pkgname ($$pkgdir) to build." ;\
						else \
							case "${BULK_PREREQ}" in \
								*$$pkgdir* ) \
									${ECHO_MSG} "BULK> Keeping BULK_PREREQ: $$pkgname ($$pkgdir)" ;\
									;; \
								* ) \
									${ECHO_MSG} ${PKG_DELETE} -r $$pkgname ; \
									${DO}       ${PKG_DELETE} -r $$pkgname || true ; \
									if ${PKG_INFO} -qe $$pkgname ; then \
										${DO}       ${PKG_DELETE} -f $$pkgname || true ; \
									fi ;\
									;; \
							esac ; \
						fi ;\
					fi ;\
				else \
					${SHCOMMENT} "Remove all pkgs" ; \
					${ECHO_MSG} ${PKG_DELETE} -r $$pkgname ; \
					${DO}       ${PKG_DELETE} -r $$pkgname || true ; \
					if ${PKG_INFO} -qe $$pkgname ; then \
						${DO}       ${PKG_DELETE} -f $$pkgname || true ; \
					fi ;\
				fi ;\
			done ; \
		fi ;\
		if [ "${USE_BULK_CACHE}" = "yes" ]; then \
			${SHCOMMENT} "Install required depends via binarypkgs XXX" ; \
			${ECHO_MSG} "BULK> Installing packages which are required to build ${PKGNAME}." ;\
			for pkgdir in `${SED} -n -e "/^${_ESCPKGPATH} / s;^[^:]*:;;p" ${DEPENDSFILE}` ${BULK_PREREQ} ; do \
				pkgname=`${GREP} "^$$pkgdir " ${INDEXFILE} | ${AWK} '{print $$2}'` ; \
				if [ -z "$$pkgname" ]; then continue ; fi ;\
				pkgfile=${PACKAGES}/All/$${pkgname}${PKG_SUFX} ;\
				if ${PKG_INFO} -qe $$pkgname ; then \
					${ECHO_MSG} "BULK> Required package $$pkgname ($$pkgdir) is already installed" ; \
				else \
					if [ -f $$pkgfile ]; then \
						${ECHO_MSG} "BULK> ${PKG_ADD} ${PKG_ARGS_ADD} $$pkgfile"; \
						${DO} ${PKG_ADD} ${PKG_ARGS_ADD} $$pkgfile || ${ECHO_MSG} "warning: could not add $$pkgfile." ; \
					else \
						${ECHO_MSG} "BULK> warning: $$pkgfile does not exist.  It will be rebuilt." ;\
					fi ;\
				fi ;\
			done ;\
		fi ;\
		if [ -f ${INTERACTIVE_COOKIE} ]; then \
			${ECHO_MSG} "BULK> Removing old marker for INTERACTIVE_STAGE..." ; \
			${ECHO_MSG} ${RM} -f ${INTERACTIVE_COOKIE} ; \
			${DO}       ${RM} -f ${INTERACTIVE_COOKIE} ; \
		fi ;\
		${ECHO_MSG} ${MAKE} package '(${PKGNAME})' 2>&1 ; \
		${DO}     ( ${MAKE} package 2>&1 ); \
		) 2>&1 | ${TEE} -a ${BUILDLOG} ; \
		if [ -f ${PKGFILE} ]; then \
			${RM} ${BUILDLOG} ; \
		else \
			${MV} ${BUILDLOG} ${BROKENFILE} ;\
			if [ -f "${WRKLOG}" ]; then \
				(${ECHO_MSG} "<pre>"; \
				${ECHO_MSG} ""; \
				${TO_HTML} ${WRKLOG}; \
				${ECHO_MSG} "</pre>"; \
				) >> ${BROKENWRKLOG}; \
			fi; \
			( \
			if [ -f "${BROKENWRKLOG}" ]; then \
				${ECHO_MSG} "</pre>"; \
				${ECHO_MSG} "<p>"; \
				${ECHO_MSG} "Please view the <a href=\"../../${PKGPATH}/${BROKENWRKLOG}\">work log for ${PKGNAME}</a>"; \
				${ECHO_MSG} "</p>"; \
				${ECHO_MSG} "<pre>"; \
				${ECHO_MSG} ""; \
			fi ; \
			${ECHO_MSG} "BULK> ${PKGNAME} was marked as broken:" ; \
			${LS} -la ${BROKENFILE} ; \
			${ECHO_MSG} ${MAKE} deinstall ; \
			${DO}       ${MAKE} deinstall ; \
			nbrokenby=0;\
			if [ "${USE_BULK_CACHE}" = "yes" ]; then \
				${ECHO_MSG} "BULK> Marking all packages which depend upon ${PKGNAME} as broken:"; \
				tmp=`${SED} -n -e "/^${_ESCPKGPATH} / s;^[^:]*:[ ]*;;p" ${SUPPORTSFILE}` ; \
				if test -n "$$tmp" ; then \
					for pkgdir in $$tmp ; do \
						pkgname=`${GREP} "^$$pkgdir " ${INDEXFILE} | ${AWK} '{print $$2}'` ;\
						if [ -z "$$pkgname" ]; then pkgname=unknown ; fi ; \
						${ECHO_MSG} "BULK> marking package that requires ${PKGNAME} as broken: $$pkgname ($$pkgdir)";\
						pkgerr="-1"; \
						pkgignore=`(cd ${PKGSRCDIR}/$$pkgdir && ${MAKE} show-var VARNAME=PKG_FAIL_REASON)`; \
						pkgskip=`(cd ${PKGSRCDIR}/$$pkgdir && ${MAKE} show-var VARNAME=PKG_SKIP_REASON)`; \
						if [ ! -z "$${pkgignore}$${pkgskip}" -a ! -f ${PKGSRCDIR}/$$pkgdir/${BROKENFILE} ]; then \
							 ${ECHO_MSG} "BULK> $$pkgname ($$pkgdir) may not be packaged because:" >> ${PKGSRCDIR}/$$pkgdir/${BROKENFILE};\
							 ${ECHO_MSG} "BULK> $$pkgignore" >> ${PKGSRCDIR}/$$pkgdir/${BROKENFILE};\
							 ${ECHO_MSG} "BULK> $$pkgskip" >> ${PKGSRCDIR}/$$pkgdir/${BROKENFILE};\
							if [ -z "`(cd ${PKGSRCDIR}/$$pkgdir && ${MAKE} show-var VARNAME=BROKEN)`" ]; then \
								pkgerr="0"; \
							else \
								pkgerr="1"; \
							fi; \
						fi; \
						${ECHO_MSG} "BULK> $$pkgname ($$pkgdir) is broken because it depends upon ${PKGNAME} (${PKGPATH}) which is broken." \
							>> ${PKGSRCDIR}/$$pkgdir/${BROKENFILE};\
						${ECHO_MSG} "Please view the <a href=\"../../${PKGPATH}/${BROKENFILE}\">build log for ${PKGNAME}</a>.<br />" \
							>> ${PKGSRCDIR}/$$pkgdir/${BROKENFILE};\
						nbrokenby=`expr $$nbrokenby + 1`;\
						if ${GREP} -q " $$pkgdir/${BROKENFILE}" ${PKGSRCDIR}/${BROKENFILE} ; then :; else \
							${ECHO} " $$pkgerr $$pkgdir/${BROKENFILE} 0 " >> ${PKGSRCDIR}/${BROKENFILE} ;\
						fi ;\
					done ;\
				fi ;\
			fi ;\
			nerrors=`${GREP} -c '^\*\*\* Error code' ${BROKENFILE} || true`; \
			if [ -f ${INTERACTIVE_COOKIE} ]; then \
				nerrors="0"; \
			fi; \
			${ECHO_MSG} " $$nerrors ${PKGPATH}/${BROKENFILE} $$nbrokenby " >> ${PKGSRCDIR}/${BROKENFILE} \
			) 2>&1 | ${TEE} -a ${BROKENFILE}; \
		fi ; \
		case ${_PRESERVE_WRKDIR} in				\
		yes|YES)	;;					\
		*)	${ECHO_MSG} "BULK> Cleaning package ${PKGNAME} and pre-requisite packages"; \
		 	if [ "${USE_BULK_CACHE}" = "yes" ]; then	\
				for pkgdir in ${PKGPATH} `${SED} -n -e "/^${_ESCPKGPATH} / s;^[^:]*:;;p" ${DEPENDSFILE}`; do \
					${DO}       (cd ${PKGSRCDIR}/$$pkgdir && ${MAKE} clean) ; \
				done;					\
			else						\
				${ECHO_MSG} ${MAKE} clean CLEANDEPENDS=YES;\
				${DO} ${MAKE} clean CLEANDEPENDS=YES;	\
			fi ;;						\
		esac;							\
	fi
	@if [ ! -f ${PKGFILE} ]; then \
		${ECHO_MSG} "BULK> Build for ${PKGNAME} was not successful, aborting." | ${TEE} -a ${BROKENFILE} ; \
		false; \
	else \
		${RM} -f ${BUILDLOG} ;\
	fi

# Install pkg - if possible from binary pkg (i.e. available & upto date)
# else revert to the old recompiling.
# Don't rely upon pkg_add to snarf in depending pkgs as they may have
# been modified and need rebuilding.
bulk-install:
	@if [ `${MAKE} bulk-check-uptodate REF=${PKGFILE}` = 1 ]; then \
		if ${PKG_INFO} -qe ${PKGNAME} ; then :; else \
			${DO} ${MAKE} install-depends ; \
			${ECHO_MSG} "BULK>" ${PKG_ADD} ${PKG_ARGS_ADD} ${PKGFILE} ; \
			${DO} ${PKG_ADD} ${PKG_ARGS_ADD} ${PKGFILE} ; \
		fi ; \
	else \
		${ECHO_MSG} ${MAKE} bulk-package PRECLEAN=no; \
		${DO}       ${MAKE} bulk-package PRECLEAN=no; \
	fi

