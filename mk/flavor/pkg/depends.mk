# $NetBSD: depends.mk,v 1.25 2007/03/15 22:14:30 rillig Exp $

_DEPENDS_FILE=		${WRKDIR}/.depends
_REDUCE_DEPENDS_CMD=	${SETENV} CAT=${CAT:Q}				\
				PKG_ADMIN=${PKG_ADMIN_CMD:Q}		\
				PWD_CMD=${PWD_CMD:Q} TEST=${TEST:Q}	\
			${AWK} -f ${PKGSRCDIR}/mk/flavor/pkg/reduce-depends.awk

# This command prints out the dependency patterns for all full (run-time)
# dependencies of the package.
#
# This is used in install.mk and metadata.mk.
#
_DEPENDS_PATTERNS_CMD=	\
	[ ! -f ${_COOKIE.depends} ]					\
	|| ${AWK} '$$1 == "full" { print $$2; }' < ${_COOKIE.depends}

_BUILD_DEPENDS_PATTERNS_CMD=	\
	[ ! -f ${_COOKIE.depends} ]					\
	|| ${AWK} '$$1 == "build" { print $$2; }' < ${_COOKIE.depends}

_flavor-show-depends: .PHONY
	@case ${VARNAME:Q}"" in						\
	BUILD_DEPENDS)	${_REDUCE_DEPENDS_CMD} ${BUILD_DEPENDS:Q} ;;	\
	DEPENDS|*)	${_REDUCE_DEPENDS_CMD} ${DEPENDS:Q} ;;		\
	esac

######################################################################
### depends-cookie (PRIVATE, pkgsrc/mk/depends/bsd.depends.mk)
######################################################################
### depends-cookie creates the "depends" cookie file.
###
### The "depends" cookie file contains all of the dependency information
### for the package.  The format of each line of the cookie file is:
###
###    <depends_type>	<pattern>	<directory>
###
### Valid dependency types are "build" and "full".
###
.PHONY: depends-cookie
depends-cookie: ${_DEPENDS_FILE}
	${RUN} [ ! -f ${_COOKIE.depends} ]
	${RUN} ${MKDIR} ${_COOKIE.depends:H}
	${RUN} ${MV} -f ${_DEPENDS_FILE} ${_COOKIE.depends}

${_DEPENDS_FILE}:
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${_REDUCE_DEPENDS_CMD} ${BUILD_DEPENDS:Q} > ${.TARGET}.build
	${RUN}								\
	exec 0< ${.TARGET}.build;					\
	while read dep; do						\
		pattern=`${ECHO} "$$dep" | ${SED} -e "s,:.*,,"`;	\
		dir=`${ECHO} "$$dep" | ${SED} -e "s,.*:,,"`;		\
		[ "$$pattern" ];					\
		[ "$$dir" ];						\
		${ECHO} "build	$$pattern	$$dir";			\
	done >> ${.TARGET}.tmp
	${RUN} ${_REDUCE_DEPENDS_CMD} ${DEPENDS:Q} > ${.TARGET}.full
	${RUN}								\
	exec 0< ${.TARGET}.full;					\
	while read dep; do						\
		pattern=`${ECHO} "$$dep" | ${SED} -e "s,:.*,,"`;	\
		dir=`${ECHO} "$$dep" | ${SED} -e "s,.*:,,"`;		\
		[ "$$pattern" ];					\
		[ "$$dir" ];						\
		${ECHO} "full	$$pattern	$$dir";			\
	done >> ${.TARGET}.tmp
	${RUN} ${MV} ${.TARGET}.tmp ${.TARGET}

# _flavor-install-dependencies:
#	Installs any missing dependencies.
#
_flavor-install-dependencies: .PHONY ${_DEPENDS_FILE}
	${RUN}								\
	while read type pattern dir rest; do				\
		{ [ "$$dir" ] && [ ! "$$rest" ]; }			\
		|| ${FAIL_MSG} "[depends.mk] Internal error #1: Check ${_DEPENDS_FILE}"; \
		silent=;						\
		${_DEPENDS_INSTALL_CMD};				\
	done < ${_DEPENDS_FILE}

######################################################################
### bootstrap-depends (PUBLIC, pkgsrc/mk/depends/depends.mk)
######################################################################
### bootstrap-depends is a public target to install any missing
### dependencies needed during stages before the normal "depends"
### stage.  These dependencies are listed in BOOTSTRAP_DEPENDS.
###
.PHONY: bootstrap-depends
bootstrap-depends:
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	args=${BOOTSTRAP_DEPENDS:S/:/ /:Q};				\
	set -- dummy $$args; shift;					\
	while ${TEST} $$# -gt 0; do					\
		pattern="$$1"; dir="$$2"; shift 2;			\
		silent=${_BOOTSTRAP_VERBOSE:Dyes};			\
		${_DEPENDS_INSTALL_CMD};				\
	done

# _DEPENDS_INSTALL_CMD expects "$pattern" to hold the dependency pattern
#	and "$dir" to hold the package directory path associated with
#	that dependency pattern.
#
_DEPENDS_INSTALL_CMD=							\
	pkg=`${_PKG_BEST_EXISTS} "$$pattern" || ${TRUE}`;		\
	case "$$pkg" in							\
	"")								\
		${STEP_MSG} "Required installed package $$pattern: NOT found"; \
		target=${DEPENDS_TARGET:Q};				\
		${STEP_MSG} "Verifying $$target for $$dir";		\
		if ${TEST} ! -d "$$dir"; then				\
			${ERROR_MSG} "[depends.mk] The directory \`\`$$dir'' does not exist."; \
			exit 1;						\
		fi;							\
		cd $$dir;						\
		${SETENV} ${PKGSRC_MAKE_ENV} _PKGSRC_DEPS=", ${PKGNAME}${_PKGSRC_DEPS}" PKGNAME_REQD="$$pattern" ${MAKE} ${MAKEFLAGS} _AUTOMATIC=yes $$target; \
		pkg=`${_PKG_BEST_EXISTS} "$$pattern" || ${TRUE}`;	\
		case "$$pkg" in						\
		"")	${ERROR_MSG} "[depends.mk] A package matching \`\`$$pattern'' should"; \
			${ERROR_MSG} "    be installed, but one cannot be found.  Perhaps there is a"; \
			${ERROR_MSG} "    stale work directory for $$dir?"; \
			exit 1;						\
		esac;							\
		${STEP_MSG} "Returning to build of ${PKGNAME}";		\
		;;							\
	*)								\
		objfmt=`${PKG_INFO} -Q OBJECT_FMT "$$pkg"`;		\
		case "$$objfmt" in					\
		"")	${WARNING_MSG} "[depends.mk] Unknown object format for installed package $$pkg" ;; \
		${OBJECT_FMT})	;;					\
		*)	${ERROR_MSG} "[depends.mk] Installed package $$pkg has an"; \
			${ERROR_MSG} "    object format \`\`$$objfmt'' which differs from \`\`${OBJECT_FMT}''.  Please"; \
			${ERROR_MSG} "    update the $$pkg package to ${OBJECT_FMT}."; \
			exit 1;						\
			;;						\
		esac;							\
		if ${TEST} -z "$$silent"; then				\
			${STEP_MSG} "Required installed package $$pattern: $$pkg found"; \
		fi;							\
		;;							\
	esac
