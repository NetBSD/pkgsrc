#	$Id: bsd.bulk-pkg.mk,v 1.16 2001/01/28 21:20:48 dmcmahill Exp $

#
# Copyright (c) 1999, 2000 Hubert Feyrer <hubertf@netbsd.org>
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

# Shall we keep the package installed after a "make bulk-package"?
# Set to "yes" by bulk-install.
KEEP?=	no

# This file exists to mark a package as broken
.ifdef OBJMACHINE
BROKENFILE?=	.broken.${MACHINE}
BUILDLOG?=	.make.${MACHINE}
.else
BROKENFILE?=	.broken
BUILDLOG?=	.make
.endif


# check if the $REF file is uptodate, i.e. is newer than any of
# the pkg files; prints "1" if upto date, "0" if not.
bulk-check-uptodate:
	@uptodate=1 ; \
	if [ -f "${REF}" ]; then \
		${SHCOMMENT} "Check files of this package" ; \
		newfiles="`find . -type f -newer "${REF}" -print  | ${EGREP} -v -e ./work -e pkg/COMMENT -e pkg/DESCR -e README.html -e CVS -e '^\./\.' || true`" ; \
		nnewfiles="`find . -type f -newer "${REF}" -print  | ${EGREP} -v -e ./work -e pkg/COMMENT -e pkg/DESCR -e README.html -e CVS -e '^\./\.' | ${WC} -l`" ; \
		if [ "$$nnewfiles" -gt 0 ]; then \
			${ECHO_MSG} >&2 "BULK> Package ${PKGNAME} ($$newfiles) modified since last 'make package' re-packaging..." ; \
			uptodate=0 ; \
		else \
			${ECHO_MSG} >&2 "BULK> ${REF} is up to date." ; \
		fi ; \
	else \
		${ECHO_MSG} >&2 "BULK> Package ${PKGNAME} not built yet, packaging..." ; \
		uptodate=0 ; \
	fi ; \
	if [ "$$uptodate" = "1" ]; then \
		${SHCOMMENT} "Check required binary packages" ; \
		deps=`${PKG_INFO} -qf ${REF} \
		      | ${GREP} ^@pkgdep \
		      | ${SED} 's,@pkgdep.,,g'`; \
		for dep in $$deps ; do \
			${SHCOMMENT} "check against the binary pkg that pkg_add would pick, too:" ; \
			${SHCOMMENT} "(Only one should be returned here, really...)" ; \
			pkg=`${PKG_ADMIN} lsbest "${PACKAGES}/All/$$dep"` ;  \
			if [ -z $$pkg ]; then \
				${ECHO_MSG} >&2 "BULK> Required binary package $$dep does not exist, rebuilding... " ; \
				uptodate=0 ; \
			elif [ "$$pkg" -nt "${REF}" ]; then \
				${ECHO_MSG} >&2 "BULK> Required binary package $$dep (`basename $$pkg`) is newer, rebuilding... " ; \
				uptodate=0 ; \
			else \
				${ECHO_MSG} >&2 "BULK> Required binary package $$dep (`basename $$pkg`) is usable. " ; \
			fi ; \
		done ; \
	fi ; \
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
	if [ "${KEEP}" = "no" ]; then \
		${ECHO_MSG} '' ; \
		${ECHO_MSG} '' ; \
		${ECHO_MSG} '###' ; \
		${ECHO_MSG} '### ${MAKE} ${.TARGET} for ${PKGNAME}' ; \
		${ECHO_MSG} '### Current pkg count: ' `${LS} -l ${PKG_DBDIR} | ${GREP} ^d | ${WC} -l` installed packages: `${LS} ${PKG_DBDIR} | ${GREP} -v pkgdb.byfile.db`; \
		${ECHO_MSG} '###' ; \
	fi \
	) 2>&1 | tee -a ${BUILDLOG}
	@uptodate=`${MAKE} ${MAKEFLAGS} bulk-check-uptodate REF=${PKGFILE}` ; \
	if ${PKG_INFO} -qe "${PKGNAME:C/-[^-]*$/-[0-9]*/}" ; then \
		installed=1; \
	else \
		installed=0; \
	fi ; \
	if [ $$uptodate = 1 ]; then \
		( if [ $$installed = 1 ]; then \
			${ECHO_MSG} "BULK> Package ${PKGNAME} is upto-date, and still installed" ; \
			${ECHO_MSG} "      removing installed package." ; \
			${ECHO_MSG} ${MAKE} deinstall DEINSTALLDEPENDS=YES ; \
			${DO}       ${MAKE} deinstall DEINSTALLDEPENDS=YES ; \
		else \
			${ECHO_MSG} "BULK> Nothing to be done." ; \
		fi \
		) 2>&1 | tee -a ${BUILDLOG}; \
	else \
		( if [ $$installed = 1 ]; then \
			${ECHO_MSG} "BULK> Removing outdated (installed) package ${PKGNAME} first." ; \
			${ECHO_MSG} ${MAKE} deinstall DEINSTALLDEPENDS=YES ; \
			${DO}       ${MAKE} deinstall DEINSTALLDEPENDS=YES ; \
		fi ; \
		if [ -f ${BUILDLOG} ]; then \
			${ECHO_MSG} "BULK> Continuing previous build..." ; \
		else \
			${ECHO_MSG} "BULK> Removing old binary package..." ; \
			${ECHO_MSG} ${RM} -f ${PKGFILE} ; \
			${DO}       ${RM} -f ${PKGFILE} ; \
			${ECHO_MSG} "BULK> Full rebuild  in progress..." ; \
			${ECHO_MSG} ${MAKE} -k clean CLEANDEPENDS=YES ; \
			${DO}       ${MAKE} -k clean CLEANDEPENDS=YES ; \
		fi ; \
		${ECHO_MSG} ${MAKE} install-depends '(${PKGNAME})' 2>&1; \
		${DO}     ( ${MAKE} install-depends 2>&1 ); \
		${ECHO_MSG} ${MAKE} package '(${PKGNAME})' 2>&1 ; \
		${DO}     ( ${MAKE} package 2>&1 ); \
		) 2>&1 | tee -a ${BUILDLOG} ; \
		if [ -f ${PKGFILE} ]; then \
			${RM} ${BUILDLOG} ; \
		else \
			( \
			${MV} ${BUILDLOG} ${BROKENFILE} ; \
			${ECHO_MSG} "BULK> ${PKGNAME} was marked as broken:" ; \
			${LS} -la ${BROKENFILE} ; \
			nerrors=`${GREP} '^\*\*\* Error code' ${BROKENFILE} | ${WC} -l`; \
			${ECHO_MSG} "$$nerrors ${PKGPATH}/${BROKENFILE}" >>../../${BROKENFILE}; \
			) 2>&1 | tee -a ${BUILDLOG}; \
		fi ; \
		${ECHO_MSG} ${MAKE} clean CLEANDEPENDS=YES ; \
		${DO}       ${MAKE} clean CLEANDEPENDS=YES ; \
		if [ "${KEEP}" = "no" ]; then \
			${ECHO_MSG} ${MAKE} deinstall DEINSTALLDEPENDS=YES ; \
			${DO}       ${MAKE} deinstall DEINSTALLDEPENDS=YES ; \
			${ECHO_MSG} ${PKG_DELETE} -rR \\* ; \
			${DO}       ${PKG_DELETE} -rR \*  >/dev/null 2>&1 || ${TRUE} ; \
		fi ; \
	fi
	@if [ ! -f ${PKGFILE} ]; then \
		${ECHO_MSG} "BULK>" Build for ${PKGNAME} was not successful, aborting. | tee -a ${BUILDLOG} ; \
		false; \
	fi

# Install pkg - if possible from binary pkg (i.e. available & upto date)
# else revert to the old recompiling. 
# Don't rely upon pkg_add to snarf in depending pkgs as they may have
# been modified and need rebuilding.
bulk-install:
	@if [ `${MAKE} bulk-check-uptodate REF=${PKGFILE}` = 1 ]; then \
		if ! ${PKG_INFO} -e ${PKGNAME} ; then \
			${DO} ${MAKE} install-depends ; \
			${ECHO_MSG} "BULK> " ${PKG_ADD} ${PKGFILE} ; \
			${DO} ${PKG_ADD} ${PKGFILE} ; \
		fi ; \
	else \
		${ECHO_MSG} ${MAKE} bulk-package KEEP=yes; \
		${DO}       ${MAKE} bulk-package KEEP=yes; \
	fi
