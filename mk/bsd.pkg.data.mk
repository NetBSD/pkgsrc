#	$NetBSD: bsd.pkg.data.mk,v 1.1.2.2 2004/11/23 20:39:19 tv Exp $
#
# bsd.pkg.mk fragments for exporting data in human-readable or machine
# parseable formats.
#
# These targets are not called internally by pkgsrc when building packages
# via the "normal" build mechanisms, but some are used by the bulk build
# system (BATCH/bsd.bulk-pkg.mk) or other external processes (README
# and README.html generation).
#
# Targets:
#
## README.html (internal only)
## binpkg-list
## cdrom-readme
## check
## describe
## fetch-list
## fetch-list-recursive (internal only)
## fetch-list-one-pkg (internal only)
## info
## lint
## list
## make-readme-html-help (internal only)
## print-build-depends-list
## print-run-depends-list
## print-summary-data
## readme [readmes]
## show-all-depends-dirs
## show-depends-dirs
## show-distfiles
## show-downlevel
## show-installed-depends
## show-license [show-licence]
## show-needs-update
## show-pkgsrc-dir
## show-pkgtools-version
## show-root-dirs
## show-vulnerabilities-html (internal only)
#

# show both build and run depends directories (non-recursively)
.PHONY: show-depends-dirs
show-depends-dirs:
	@dlist="";							\
	thisdir=`${PWD_CMD}`;						\
	for reldir in "" ${DEPENDS:C/^[^:]*://:C/:.*$//} ${BUILD_DEPENDS:C/^[^:]*://:C/:.*$//} ;\
	do								\
		if [ "X$$reldir" = "X" ]; then continue; fi;		\
		cd $$thisdir/$$reldir;					\
		WD=`${PWD_CMD}`;					\
		d=`dirname $$WD`;					\
		absdir=`basename $$d`/`basename $$WD`;			\
		dlist="$$dlist $$absdir";				\
	done;								\
	cd $$thisdir;							\
	${ECHO} "$$dlist"

# Show all build and run depends, reverse-breadth first, with options.

# "awk" macro to recurse over the dependencies efficiently, never running in
# the same same directory twice. You may set the following options via "-v":
#
#	NonSelf = 1	to not print own directory;
#	RootsOnly = 1	to print only root directories (i.e. directories
#			of packages with no dependencies), including possibly
#			own directory
#
_RECURSE_DEPENDS_DIRS=							\
	function append_dirs(dir) {					\
		command = "cd ../../" dir " && ${MAKE} show-depends-dirs"; \
		command | getline tmp_dirs;				\
		close(command);						\
		if (tmp_dirs ~ /^$$/)					\
			root_dirs[p++] = dir;				\
		for (i = 1; i <= split(tmp_dirs, tmp_r); i++)		\
			if (!(tmp_r[i] in hash_all_dirs)) {		\
				all_dirs[n++] = tmp_r[i];		\
				hash_all_dirs[tmp_r[i]] = 1		\
			}						\
	}								\
	BEGIN {								\
		command = "${PWD_CMD}";					\
		command | getline start_dir;				\
		close(command);						\
		i = split(start_dir, tmp_r, /\//);			\
		all_dirs[n++] = tmp_r[i-1] "/" tmp_r[i];		\
		for (; m < n; )						\
			append_dirs(all_dirs[m++]);			\
		if (RootsOnly) {					\
			printf("%s", root_dirs[--p]);			\
			for (; p > 0; )					\
				printf(" %s", root_dirs[--p])		\
		}							\
		else {							\
			if (m > NonSelf)				\
				printf("%s", all_dirs[--m]);		\
			for (; m > NonSelf; )				\
				printf(" %s", all_dirs[--m])		\
		}							\
		print							\
	}

_SHOW_ALL_DEPENDS_DIRS_EXCL=	${AWK} -v NonSelf=1 '${_RECURSE_DEPENDS_DIRS}'

.PHONY: show-all-depends-dirs
show-all-depends-dirs:
	@${AWK} '${_RECURSE_DEPENDS_DIRS}'

.PHONY: show-root-dirs
show-root-dirs:
	${_PKG_SILENT}${_PKG_DEBUG}${AWK} -v RootsOnly=1 '${_RECURSE_DEPENDS_DIRS}'

.PHONY: show-distfiles
show-distfiles:
.if !defined(PKG_FAIL_REASON)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for file in "" ${_CKSUMFILES}; do				\
		if [ "X$$file" = "X" ]; then continue; fi;		\
		${ECHO} $$file;						\
	done
.endif

.PHONY: show-downlevel
show-downlevel:
.if !defined(PKG_FAIL_REASON)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_BEST_EXISTS} \"${PKGWILDCARD}\" || ${TRUE}`";	\
	if [ "X$$found" != "X" -a "X$$found" != "X${PKGNAME}" ]; then	\
		${ECHO} "${PKGBASE} package: $$found installed, pkgsrc version ${PKGNAME}"; \
		if [ "X$$STOP_DOWNLEVEL_AFTER_FIRST" != "X" ]; then	\
			${ECHO} "stopping after first downlevel pkg found"; \
			exit 1;						\
		fi;							\
	fi
.endif

.PHONY: show-installed-depends
show-installed-depends:
.if !empty(DEPENDS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for i in ${DEPENDS:C/:.*$//:Q:S/\ / /g} ; do			\
		echo "$$i =>" `${PKG_BEST_EXISTS} "$$i"` ;		\
	done
.endif

.PHONY: show-needs-update
show-needs-update:
.if !empty(DEPENDS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for i in `${MAKE} show-all-depends-dirs`; do			\
		cd ${PKGSRCDIR}/$$i;					\
		want=`${MAKE} show-var-noeval VARNAME=PKGNAME`;		\
		wild=`${MAKE} show-var-noeval VARNAME=PKGWILDCARD`;	\
		have=`${PKG_BEST_EXISTS} "$$wild" || ${TRUE}`;		\
		if [ -z "$$have" ]; then				\
			${ECHO} "$$i => (none) => needs install of $$want"; \
		elif [ "$$have" != "$$want" ]; then			\
			${ECHO} "$$i => $$have => needs update to $$want"; \
		fi;							\
	done
.endif

.PHONY: show-pkgsrc-dir
show-pkgsrc-dir:
.if !defined(PKG_FAIL_REASON)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_BEST_EXISTS} \"${PKGWILDCARD}\" || ${TRUE}`";	\
	if [ "X$$found" != "X" ]; then					\
		${ECHO} ${PKGPATH};					\
	fi
.endif

# The 'info' target can be used to display information about a package.
.PHONY: info
info:
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_INFO} "${PKGWILDCARD}"

# The 'check' target can be used to check an installed package.
.PHONY: check
check:
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_ADMIN} check "${PKGWILDCARD}"

# The 'list' target can be used to list the files installed by a package.
.PHONY: list
list:
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_INFO} -L "${PKGWILDCARD}"

# Run pkglint:
.PHONY: lint
lint:
	${_PKG_SILENT}${_PKG_DEBUG}${LOCALBASE}/bin/pkglint | ${GREP} -v ^OK

# Prints out a script to fetch all needed files (no checksumming).
.PHONY: fetch-list
fetch-list:
	@${ECHO} '#!/bin/sh'
	@${ECHO} '#'
	@${ECHO} '# This is an auto-generated script, the result of running'
	@${ECHO} '# `${MAKE} fetch-list'"'"' in directory "'"`${PWD_CMD}`"'"'
	@${ECHO} '# on host "'"`${UNAME} -n`"'" on "'"`date`"'".'
	@${ECHO} '#'
	@${MAKE} ${MAKEFLAGS} fetch-list-recursive

.PHONY: fetch-list-recursive
fetch-list-recursive:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for dir in `${MAKE} ${MAKEFLAGS} show-all-depends-dirs`; do	\
		(cd ../../$$dir &&					\
		${MAKE} ${MAKEFLAGS} fetch-list-one-pkg			\
		| ${AWK} '						\
		/^[^#]/ { FoundSomething = 1 }				\
		/^unsorted/ { gsub(/[[:space:]]+/, " \\\n\t") }		\
		/^echo/ { gsub(/;[[:space:]]+/, "\n") }			\
		{ block[line_c++] = $$0 }				\
		END { if (FoundSomething)				\
			for (line = 0; line < line_c; line++)		\
				print block[line] }			\
		')							\
	done

.PHONY: fetch-list-one-pkg
fetch-list-one-pkg:
.if !empty(_ALLFILES)
	@${ECHO}
	@${ECHO} '#'
	@location=`${PWD_CMD} | ${AWK} -F / '{ print $$(NF-1) "/" $$NF }'`; \
		${ECHO} '# Need additional files for ${PKGNAME} ('$$location')...'
	@${ECHO} '#'
	@${MKDIR} ${_DISTDIR}
.  for fetchfile in ${_ALLFILES}
.    if defined(_FETCH_MESSAGE)
	@(cd ${_DISTDIR};						\
	if [ ! -f ${fetchfile:T} ]; then				\
		${ECHO};						\
		filesize=`${AWK} '					\
			/^Size/ && $$2 == "(${fetchfile})" { print $$4 } \
			' ${DISTINFO_FILE}` || true;			\
		${ECHO} '# Prompt user to get ${fetchfile} ('$${filesize-???}' bytes) manually:'; \
		${ECHO} '#';						\
		${ECHO} ${_FETCH_MESSAGE:Q};				\
	fi)
.    elif defined(DYNAMIC_MASTER_SITES)
	@(cd ${_DISTDIR};						\
	if [ ! -f ${fetchfile:T} ]; then				\
		${ECHO};						\
		filesize=`${AWK} '					\
			/^Size/ && $$2 == "(${fetchfile})" { print $$4 } \
			' ${DISTINFO_FILE}` || true;			\
		${ECHO} '# Fetch ${fetchfile} ('$${filesize-???}' bytes):'; \
		${ECHO} '#';						\
		${ECHO} '${SH} -s ${fetchfile:T} <<"EOF" |(';		\
		${CAT} ${FILESDIR}/getsite.sh;				\
		${ECHO} EOF;						\
		${ECHO} read unsorted_sites;				\
		${ECHO} 'unsorted_sites="$${unsorted_sites} ${_MASTER_SITE_BACKUP}"'; \
		${ECHO} sites='"'${ORDERED_SITES:Q}'"';			\
		${ECHO} "${MKDIR} ${_DISTDIR}";				\
		${ECHO} 'cd ${_DISTDIR} && [ -f ${fetchfile} -o -f ${fetchfile:T} ] ||'; \
		${ECHO}	'for site in $$sites; do';			\
		${ECHO} '	${FETCH_CMD} ${FETCH_BEFORE_ARGS} "$${site}${fetchfile:T}" ${FETCH_AFTER_ARGS} && break ||'; \
		${ECHO} '	${ECHO} ${fetchfile} not fetched';	\
		${ECHO}	done;						\
		${ECHO} ')';						\
	fi)
.    else
	@(cd ${_DISTDIR};						\
	if [ ! -f ${fetchfile:T} ]; then				\
		${ECHO};						\
		filesize=`${AWK} '					\
			/^Size/ && $$2 == "(${fetchfile})" { print $$4 } \
			' ${DISTINFO_FILE}` || true;			\
		${ECHO} '# Fetch ${fetchfile} ('$${filesize-???}' bytes):'; \
		${ECHO} '#';						\
		${ECHO} 'unsorted_sites="${SITES_${fetchfile:T:S/=/--/}} ${_MASTER_SITE_BACKUP}"'; \
		${ECHO} sites='"'${ORDERED_SITES:Q}'"';			\
		${ECHO} "${MKDIR} ${_DISTDIR}";				\
		${ECHO} 'cd ${_DISTDIR} && [ -f ${fetchfile} -o -f ${fetchfile:T} ] ||'; \
		${ECHO}	'for site in $$sites; do';			\
		${ECHO} '	${FETCH_CMD} ${FETCH_BEFORE_ARGS} "$${site}${fetchfile:T}" ${FETCH_AFTER_ARGS} && break ||'; \
		${ECHO} '	${ECHO} ${fetchfile} not fetched';	\
		${ECHO}	done;						\
	fi)
.    endif # defined(_FETCH_MESSAGE) || defined(DYNAMIC_MASTER_SITES)
.  endfor
.endif # !empty(_ALLFILES)

.PHONY: make-readme-html-help
make-readme-html-help:
	@${ECHO} '${PKGNAME:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g}</a>: <TD>'${COMMENT:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g:Q}

# If PACKAGES is set to the default (../../pkgsrc/packages), the current
# ${MACHINE_ARCH} and "release" (uname -r) will be used. Otherwise a directory
# structure of ...pkgsrc/packages/`uname -r`/${MACHINE_ARCH} is assumed.
# The PKG_URL is set from FTP_PKG_URL_* or CDROM_PKG_URL_*, depending on
# the target used to generate the README.html file.
.PHONY: binpkg-list
binpkg-list:
	@if ${TEST} -d ${PACKAGES}; then				\
		cd ${PACKAGES};						\
		case ${.CURDIR} in					\
		*/pkgsrc/packages)					\
			for pkg in ${PKGREPOSITORYSUBDIR}/${PKGWILDCARD}${PKG_SUFX} ; \
			do 						\
				if [ -f "$$pkg" ] ; then		\
					pkgname=`${ECHO} $$pkg | ${SED} 's@.*/@@'`; \
					${ECHO} "<TR><TD>${MACHINE_ARCH}:<TD><a href=\"${PKG_URL}/$$pkg\">$$pkgname</a><TD>(${OPSYS} ${OS_VERSION})"; \
				fi ;					\
			done ; 						\
			;;						\
		*)							\
			cd ${PACKAGES}/../..;				\
			for i in [1-9].*/*; do  			\
				if cd ${PACKAGES}/../../$$i/${PKGREPOSITORYSUBDIR} 2>/dev/null; then \
					for j in ${PKGWILDCARD}${PKG_SUFX}; \
					do 				\
						if [ -f "$$j" ]; then	\
							${ECHO} $$i/$$j;\
						fi;			\
					done; 				\
				fi; 					\
			done | ${AWK} -F/ '				\
				{					\
					release = $$1;			\
					arch = $$2; 			\
					pkg = $$3;			\
					gsub("\\.tgz","", pkg);		\
					if (arch != "m68k" && arch != "mipsel") { \
						if (arch in urls)	\
							urls[arch "/" pkg "/" release] = "<a href=\"${PKG_URL}/" release "/" arch "/${PKGREPOSITORYSUBDIR}/" pkg "${PKG_SUFX}\">" pkg "</a>, " urls[arch]; \
						else			\
							urls[arch "/" pkg "/" release] = "<a href=\"${PKG_URL}/" release "/" arch "/${PKGREPOSITORYSUBDIR}/" pkg "${PKG_SUFX}\">" pkg "</a> "; \
					}				\
				} 					\
				END { 					\
					for (av in urls) {		\
						split(av, ava, "/");	\
						arch=ava[1];		\
						pkg=ava[2];		\
						release=ava[3];		\
						print "<TR><TD>" arch ":<TD>" urls[av] "<TD>(${OPSYS} " release ")"; \
					}				\
				}' | ${SORT}				\
			;;						\
		esac;							\
	fi

# This target generates an index entry suitable for aggregation into
# a large index.  Format is:
#
# distribution-name|package-path|installation-prefix|comment| \
#  description-file|maintainer|categories|build deps|run deps|for arch| \
#  not for opsys
#
.PHONY: describe
describe:
	@${ECHO_N} "${PKGNAME}|${.CURDIR}|";				\
	${ECHO_N} "${PREFIX}|";						\
	${ECHO_N} ${COMMENT:Q};						\
	if [ -f ${DESCR_SRC} ]; then					\
		${ECHO_N} "|${DESCR_SRC}";				\
	else								\
		${ECHO_N} "|/dev/null";					\
	fi;								\
	${ECHO_N} "|${MAINTAINER}|${CATEGORIES}|";			\
	case "A${BUILD_DEPENDS}B${DEPENDS}C" in	\
		ABC) ;;							\
		*) cd ${.CURDIR} && ${ECHO_N} `${MAKE} ${MAKEFLAGS} build-depends-list | ${SORT} -u`;; \
	esac;								\
	${ECHO_N} "|";							\
	if [ "${DEPENDS}" != "" ]; then					\
		cd ${.CURDIR} && ${ECHO_N} `${MAKE} ${MAKEFLAGS} run-depends-list | ${SORT} -u`; \
	fi;								\
	${ECHO_N} "|";							\
	if [ "${ONLY_FOR_ARCHS}" = "" ]; then				\
		${ECHO_N} "any";					\
	else								\
		${ECHO_N} "${ONLY_FOR_ARCHS}";				\
	fi;								\
	${ECHO_N} "|";							\
	if [ "${NOT_FOR_OPSYS}" = "" ]; then				\
		${ECHO_N} "any";					\
	else								\
		${ECHO_N} "not ${NOT_FOR_OPSYS}";			\
	fi;								\
	${ECHO} ""

# This target is used to generate README.html files
FTP_PKG_URL_HOST?=	ftp://ftp.NetBSD.org
FTP_PKG_URL_DIR?=	/pub/NetBSD/packages

.PHONY: readme readmes
readme readmes:
	@cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} README.html PKG_URL=${FTP_PKG_URL_HOST}${FTP_PKG_URL_DIR}

# This target is used to generate README.html files, very like "readme"
# However, a different target was used for ease of use.
CDROM_PKG_URL_HOST?=	file://localhost
CDROM_PKG_URL_DIR?=	/usr/pkgsrc/packages

.PHONY: cdrom-readme
cdrom-readme:
	@cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} README.html PKG_URL=${CDROM_PKG_URL_HOST}${CDROM_PKG_URL_DIR}

README_NAME=	${TEMPLATES}/README.pkg

# set up the correct license information as a sed expression
.ifdef LICENSE
SED_LICENSE_EXPR=       -e 's|%%LICENSE%%|<p>Please note that this package has a ${LICENSE} license.</p>|'
.else
SED_LICENSE_EXPR=       -e 's|%%LICENSE%%||'
.endif

# set up the "more info URL" information as a sed expression
.ifdef HOMEPAGE
SED_HOMEPAGE_EXPR=       -e 's|%%HOMEPAGE%%|<p>This package has a home page at <a HREF="${HOMEPAGE}">${HOMEPAGE}</a>.</p>|'
.else
SED_HOMEPAGE_EXPR=       -e 's|%%HOMEPAGE%%||'
.endif

.PHONY: show-vulnerabilities-html
show-vulnerabilities-html:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -f ${PKGVULNDIR}/pkg-vulnerabilities ]; then			\
		${AWK} '/^${PKGBASE}[-<>=]+[0-9]/ { gsub("\<", "\\&lt;", $$1);	\
			 gsub("\>", "\\&gt;", $$1);			\
			 printf("<LI><STRONG>%s has a %s exploit (see <a href=\"%s\">%s</a> for more details)</STRONG></LI>\n", $$1, $$2, $$3, $$3) }' \
			${PKGVULNDIR}/pkg-vulnerabilities;			\
	fi

# If PACKAGES is set to the default (../../packages), the current
# ${MACHINE_ARCH} and "release" (uname -r) will be used. Otherwise a directory
# structure of ...pkgsrc/packages/`uname -r`/${MACHINE_ARCH} is assumed.
# The PKG_URL is set from FTP_PKG_URL_* or CDROM_PKG_URL_*, depending on
# the target used to generate the README.html file.
.PHONY: README.html
README.html: .PRECIOUS
	@${SETENV} AWK=${AWK} BMAKE=${MAKE} ../../mk/scripts/mkdatabase -f $@.tmp1
	@if ${TEST} -d ${PACKAGES}; then					\
		cd ${PACKAGES};						\
		case `${PWD_CMD}` in					\
			${PKGSRCDIR}/packages)				\
				MULTIARCH=no;				\
				;;					\
			*)						\
				MULTIARCH=yes;				\
				;;					\
		esac;							\
		cd ${.CURDIR} ;						\
	fi;								\
	${AWK} -f ../../mk/scripts/genreadme.awk \
		builddependsfile=/dev/null \
		dependsfile=/dev/null \
		DISTDIR=${DISTDIR} \
		MACHINE_ARCH=${MACHINE_ARCH} \
		MULTIARCH=$$MULTIARCH \
		OPSYS=${OPSYS} \
		OS_VERSION=${OS_VERSION} \
		PACKAGES=${PACKAGES} \
		PKG_SUFX=${PKG_SUFX} \
		PKG_URL=${PKG_URL} \
		PKGREPOSITORYSUBDIR=${PKGREPOSITORYSUBDIR} \
		PKGSRCDIR=${.CURDIR:C|/[^/]*/[^/]*$||} \
		TMPDIR=${TMPDIR:U/tmp} \
		SINGLEPKG=${PKGPATH} \
		$@.tmp1
	@${RM} $@.tmp1

.PHONY: show-pkgtools-version
show-pkgtools-version:
	@${ECHO} ${PKGTOOLS_VERSION}

.PHONY: print-build-depends-list
print-build-depends-list:
.if !empty(BUILD_DEPENDS) || !empty(DEPENDS)
	@${ECHO_N} 'This package requires package(s) "'
	@${ECHO_N} `${MAKE} ${MAKEFLAGS} build-depends-list | ${SORT} -u`
	@${ECHO} '" to build.'
.endif

.PHONY: print-run-depends-list
print-run-depends-list:
.if !empty(DEPENDS)
	@${ECHO_N} 'This package requires package(s) "'
	@${ECHO_N} `${MAKE} ${MAKEFLAGS} run-depends-list | ${SORT} -u`
	@${ECHO} '" to run.'
.endif

# This target is used by the mk/scripts/mkreadme script to generate
# README.html files
.PHONY: print-summary-data
print-summary-data:
	@${ECHO} "depends ${PKGPATH} ${DEPENDS}"
	@${ECHO} "build_depends ${PKGPATH} ${BUILD_DEPENDS}"
	@${ECHO} "conflicts ${PKGPATH} ${CONFLICTS}"
	@${ECHO} "index ${PKGPATH} ${PKGNAME}"
	@${ECHO} htmlname ${PKGPATH} ${HTML_PKGNAME:Q}
	@${ECHO} homepage ${PKGPATH} ${HOMEPAGE:Q}
	@${ECHO} wildcard ${PKGPATH} ${PKGWILDCARD:Q}
	@${ECHO} comment ${PKGPATH} ${COMMENT:Q}
	@${ECHO} license ${PKGPATH} ${LICENSE:Q}
	@if [ "${ONLY_FOR_ARCHS}" = "" ]; then				\
		${ECHO} "onlyfor ${PKGPATH} any";			\
	else								\
		${ECHO} "onlyfor ${PKGPATH} ${ONLY_FOR_ARCHS}";		\
	fi;
	@if [ "${NOT_FOR_OPSYS}" = "" ]; then				\
		${ECHO} "notfor ${PKGPATH} any";			\
	else								\
		${ECHO} "notfor ${PKGPATH} not ${NOT_FOR_OPSYS}";	\
	fi;
	@${ECHO} "maintainer ${PKGPATH} ${MAINTAINER}"
	@${ECHO} "categories ${PKGPATH} ${CATEGORIES}"
	@if [ -f ${DESCR_SRC} ]; then						\
		${ECHO}  "descr ${PKGPATH} ${DESCR_SRC:S;${PKGSRCDIR}/;;g}";	\
	else									\
		${ECHO}  "descr ${PKGPATH} /dev/null";				\
	fi
	@${ECHO} "prefix ${PKGPATH} ${PREFIX}"

.PHONY: show-license show-licence
show-license show-licence:
	@if [ "${LICENSE}" != "" ]; then				\
		if ${TEST} -f ${PKGSRCDIR}/licenses/${LICENSE}; then	\
			if [ "${PAGER}" != "" ]; then			\
				${PAGER} ${PKGSRCDIR}/licenses/${LICENSE};\
			else						\
				${CAT} ${PKGSRCDIR}/licenses/${LICENSE};\
			fi						\
		else							\
			${ECHO} "Generic ${LICENSE} information not available"; \
			${ECHO} "See the package description (pkg_info -d ${PKGNAME}) for more information."; \
		fi							\
	fi
