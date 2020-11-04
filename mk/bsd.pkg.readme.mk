# $NetBSD: bsd.pkg.readme.mk,v 1.29 2020/11/04 16:38:59 khorben Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and encapsulates the
# code to produce README.html files in each package directory.
#
# The following are the "public" targets provided by this module.
#
#    readme		This target generates a README.html file suitable
#			for being served via FTP.
#
#    cdrom-readme	This target generates a README.html file suitable
#			for being served from a mounted CD-ROM.
#
# The following are the user-settable variables that may be defined in
# /etc/mk.conf.
#
#    FTP_PKG_URL_HOST is the host portion of the URL to embed in each
#	README.html file to be served via FTP, and defaults to
#	"ftp://ftp.NetBSD.org".
#
#    FTP_PKG_URL_DIR is the directory portion of the URL to embed in each
#	README.html file to be served via FTP, and defaults to
#	"/pub/pkgsrc/packages".
#
#    CDROM_PKG_URL_HOST is the host portion of the URL to embed in each
#	README.html file to be served from a mounted CD-ROM, and defaults
#	to "file://localhost".
#
#    CDROM_PKG_URL_DIR is the directory portion of the URL to embed in each
#	README.html file to be served from a mounted CD-ROM, and defaults
#	to "/usr/pkgsrc/packages".
#

# Set to "html" by the README.html target to generate HTML code.
# This variable is passed down via build-depends-list and run-depends-list
PACKAGE_NAME_TYPE?=	name

_HTML_PKGLINK=		<a href="../../${PKGPATH}/README.html">${PKGNAME}</a>

.PHONY: package-name
.if !target(package-name)
package-name:
.  if (${PACKAGE_NAME_TYPE} == "html")
	@${ECHO} ${_HTML_PKGLINK:Q}
.  elif (${PACKAGE_NAME_TYPE} == "path")
	@${ECHO} ${PKGPATH}
.  else
	@${ECHO} ${PKGNAME}
.  endif # PACKAGE_NAME_TYPE
.endif # !target(package-name)

.PHONY: make-readme-html-help
.if !target(make-readme-html-help)
make-readme-html-help:
	@${ECHO} '${PKGNAME}</a>: <TD>'${COMMENT:Q}
.endif # !target(make-readme-html-help)

# Show (non-recursively) all the packages this package depends on.
# If PACKAGE_DEPENDS_WITH_PATTERNS is set, print as pattern (if possible)
PACKAGE_DEPENDS_WITH_PATTERNS?=true
.PHONY: run-depends-list
.if !target(run-depends-list)
run-depends-list:
.  for dep in ${DEPENDS}
	@pkg="${dep:C/:.*//}";						\
	dir="${dep:C/[^:]*://}";					\
	cd ${.CURDIR};							\
	if ${PACKAGE_DEPENDS_WITH_PATTERNS}; then			\
		${ECHO} "$$pkg";					\
	else								\
		if cd $$dir 2>/dev/null; then				\
			${RECURSIVE_MAKE} ${MAKEFLAGS} package-name PACKAGE_NAME_TYPE=${PACKAGE_NAME_TYPE}; \
		else 							\
			${ECHO_MSG} "Warning: \"$$dir\" non-existent -- @pkgdep registration incomplete" >&2; \
		fi;							\
	fi
.  endfor
.endif # target(run-depends-list)

.PHONY: build-depends-list
.if !target(build-depends-list)
build-depends-list:
	@${_DEPENDS_WALK_CMD} ${PKGPATH} |				\
	while read dir; do						\
		( cd ../../$$dir && ${RECURSIVE_MAKE} ${MAKEFLAGS} package-name) \
	done
.endif

# If PACKAGES is set to the default (../../pkgsrc/packages), the current
# ${MACHINE_ARCH} and "release" (uname -r) will be used. Otherwise a directory
# structure of ...pkgsrc/packages/`uname -r`/${MACHINE_ARCH} is assumed.
# The PKG_URL is set from FTP_PKG_URL_* or CDROM_PKG_URL_*, depending on
# the target used to generate the README.html file.
.PHONY: binpkg-list
.if !target(binpkg-list)
binpkg-list:
	@if ${TEST} -d ${PACKAGES}; then					\
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
.endif

# This target generates an index entry suitable for aggregation into
# a large index.  Format is:
#
# distribution-name|package-path|installation-prefix|comment| \
#  description-file|maintainer|categories|build deps|run deps|for arch| \
#  not for opsys
#
# XXX Need to handle BUILD_DEPENDS/TOOL_DEPENDS split.
#
.PHONY: describe
.if !target(describe)
describe:
	@${ECHO_N} "${PKGNAME}|${.CURDIR}|";				\
	${ECHO_N} "${PREFIX}|";						\
	${ECHO_N} ${COMMENT:Q};						\
	if [ -f "${DESCR_SRC}" ]; then					\
		${ECHO_N} "|${DESCR_SRC}";				\
	else								\
		${ECHO_N} "|/dev/null";					\
	fi;								\
	${ECHO_N} "|${MAINTAINER}|${CATEGORIES}|";			\
	case "A${BUILD_DEPENDS}B${DEPENDS}C" in	\
		ABC) ;;							\
		*) cd ${.CURDIR} && ${ECHO_N} `${RECURSIVE_MAKE} ${MAKEFLAGS} build-depends-list | ${SORT} -u`;; \
	esac;								\
	${ECHO_N} "|";							\
	if [ "${DEPENDS}" != "" ]; then					\
		cd ${.CURDIR} && ${ECHO_N} `${RECURSIVE_MAKE} ${MAKEFLAGS} run-depends-list | ${SORT} -u`; \
	fi;								\
	${ECHO_N} "|";							\
	if [ "${ONLY_FOR_PLATFORM}" = "" ]; then			\
		${ECHO_N} "any";					\
	else								\
		${ECHO_N} "${ONLY_FOR_PLATFORM}";			\
	fi;								\
	${ECHO_N} "|";							\
	if [ "${NOT_FOR_PLATFORM}" = "" ]; then				\
		${ECHO_N} "any";					\
	else								\
		${ECHO_N} "not ${NOT_FOR_PLATFORM}";			\
	fi;								\
	${ECHO} ""
.endif

.PHONY: readmes
.if !target(readmes)
readmes:	readme
.endif

# This target is used to generate README.html files
.PHONY: readme
.if !target(readme)
FTP_PKG_URL_HOST?=	ftp://ftp.NetBSD.org
FTP_PKG_URL_DIR?=	/pub/pkgsrc/packages

readme:
	@cd ${.CURDIR} && ${RECURSIVE_MAKE} ${MAKEFLAGS} README.html PKG_URL=${FTP_PKG_URL_HOST}${FTP_PKG_URL_DIR}
.endif

# This target is used to generate README.html files, very like "readme"
# However, a different target was used for ease of use.
.PHONY: cdrom-readme
.if !target(cdrom-readme)
CDROM_PKG_URL_HOST?=	file://localhost
CDROM_PKG_URL_DIR?=	/usr/pkgsrc/packages

cdrom-readme:
	@cd ${.CURDIR} && ${RECURSIVE_MAKE} ${MAKEFLAGS} README.html PKG_URL=${CDROM_PKG_URL_HOST}${CDROM_PKG_URL_DIR}
.endif

README_NAME=	${TEMPLATES}/README.pkg

# set up the correct license information as a sed expression
.if defined(LICENSE)
SED_LICENSE_EXPR=	-e 's|%%LICENSE%%|<p>Please note that this package has a ${LICENSE} license.</p>|'
.else
SED_LICENSE_EXPR=	-e 's|%%LICENSE%%||'
.endif

# set up the "more info URL" information as a sed expression
.if defined(HOMEPAGE)
SED_HOMEPAGE_EXPR=	-e 's|%%HOMEPAGE%%|<p>This package has a home page at <a HREF="${HOMEPAGE}">${HOMEPAGE}</a>.</p>|'
.else
SED_HOMEPAGE_EXPR=	-e 's|%%HOMEPAGE%%||'
.endif

# If PACKAGES is set to the default (../../packages), the current
# ${MACHINE_ARCH} and "release" (uname -r) will be used. Otherwise a directory
# structure of ...pkgsrc/packages/`uname -r`/${MACHINE_ARCH} is assumed.
# The PKG_URL is set from FTP_PKG_URL_* or CDROM_PKG_URL_*, depending on
# the target used to generate the README.html file.
.PHONY: README.html
README.html: .PRECIOUS
	@${PKGSRC_SETENV} BMAKE=${MAKE:Q} ${SH} ../../mk/scripts/mkdatabase -f $@.tmp1
	@if ${TEST} -d ${PACKAGES}; then				\
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
	if [ `${PKG_ADMIN} -V` -lt 20080415 ]; then			\
		SCAN_VULNERABILITIES=0;					\
	else								\
	_PVDIR=`${PKG_ADMIN} config-var PKGVULNDIR`;			\
	if [ -e "$${_PVDIR}"/pkg-vulnerabilities ]; then		\
		SCAN_VULNERABILITIES=2;					\
	else								\
		SCAN_VULNERABILITIES=1;					\
	fi;								\
	fi;								\
	${AWK} -f ../../mk/scripts/genreadme.awk \
		builddependsfile=/dev/null \
		dependsfile=/dev/null \
		AWK=${AWK:Q} \
		CMP=${CMP:Q} \
		DISTDIR=${DISTDIR:Q} \
		GREP=${GREP:Q} \
		PACKAGES=${PACKAGES:Q} \
		PKG_ADMIN=${PKG_ADMIN:Q} \
		PKG_INFO=${PKG_INFO:Q} \
		PKG_SUFX=${PKG_SUFX:Q} \
		PKG_URL=${PKG_URL:Q} \
		PKGSRCDIR=${.CURDIR:C|/[^/]*/[^/]*$||:Q} \
		PKGTOOLS_VERSION=${PKGTOOLS_VERSION} \
		SCAN_VULNERABILITIES=$${SCAN_VULNERABILITIES} \
		SED=${SED:Q} \
		SETENV=${SETENV:Q} \
		SORT=${SORT:Q} \
		TMPDIR=${TMPDIR:U/tmp:Q} \
		SINGLEPKG=${PKGPATH:Q} \
		$@.tmp1
	@${RM} $@.tmp1

.PHONY: print-build-depends-list
.if !target(print-build-depends-list)
print-build-depends-list:
.  if !empty(BUILD_DEPENDS) || !empty(DEPENDS)
	@${ECHO_N} 'This package requires package(s) "'
	@${ECHO_N} `${RECURSIVE_MAKE} ${MAKEFLAGS} build-depends-list | ${SORT} -u`
	@${ECHO} '" to build.'
.  endif
.endif

.PHONY: print-run-depends-list
.if !target(print-run-depends-list)
print-run-depends-list:
.  if !empty(DEPENDS)
	@${ECHO_N} 'This package requires package(s) "'
	@${ECHO_N} `${RECURSIVE_MAKE} ${MAKEFLAGS} run-depends-list | ${SORT} -u`
	@${ECHO} '" to run.'
.  endif
.endif

# This target is used by the mk/scripts/mkreadme script to generate
# README.html files
.PHONY: print-summary-data
.if !target(print-summary-data)
print-summary-data:
	@${ECHO} depends ${PKGPATH} ${DEPENDS:Q}
	@${ECHO} build_depends ${PKGPATH} ${BUILD_DEPENDS:Q}
	@${ECHO} conflicts ${PKGPATH} ${CONFLICTS:Q}
	@${ECHO} index ${PKGPATH} ${PKGNAME:Q}
	@${ECHO} htmlname ${PKGPATH} ${_HTML_PKGLINK:Q}
	@${ECHO} homepage ${PKGPATH} ${HOMEPAGE:Q}
	@${ECHO} wildcard ${PKGPATH} ${PKGWILDCARD:Q}
	@${ECHO} comment ${PKGPATH} ${COMMENT:Q}
	@${ECHO} license ${PKGPATH} ${LICENSE:Q}
	@if [ "${ONLY_FOR_PLATFORM}" = "" ]; then			\
		${ECHO} "onlyfor ${PKGPATH} any";			\
	else								\
		${ECHO} "onlyfor ${PKGPATH} ${ONLY_FOR_PLATFORM}";	\
	fi
	@if [ "${NOT_FOR_PLATFORM}" = "" ]; then			\
		${ECHO} "notfor ${PKGPATH} any";			\
	else								\
		${ECHO} "notfor ${PKGPATH} not ${NOT_FOR_PLATFORM}";	\
	fi;
	@if [ -n "${OWNER}" ]; then					\
		${ECHO} "owner ${PKGPATH} ${OWNER}";			\
	else								\
		${ECHO} "maintainer ${PKGPATH} ${MAINTAINER}";		\
	fi
	@${ECHO} "categories ${PKGPATH} ${CATEGORIES}"
	@if [ -f "${DESCR_SRC}" ]; then					\
		${ECHO}  "descr ${PKGPATH} ${DESCR_SRC:S;${PKGSRCDIR}/;;g}"; \
	else								\
		${ECHO}  "descr ${PKGPATH} /dev/null";			\
	fi
	@${ECHO} "prefix ${PKGPATH} ${PREFIX}"
.endif
