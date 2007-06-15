# $NetBSD: depends.mk,v 1.38 2007/06/15 10:39:08 rillig Exp $

# This command prints out the dependency patterns for all full (run-time)
# dependencies of the package.
#
# This is used in install.mk and metadata.mk.
#

# ${_DEPENDS_FILE} contains all the dependency information
# for the package.  The format of each line of the file is:
#
#	<depends_type>	<pattern>	<directory>
#
# Valid dependency types are "bootstrap", "build" and "full".
#
# ${_RDEPENDS_FILE} contains the resolved dependency information
# for the package.  For each line in ${_DEPENDS_FILE}
# a corresponding line of the following form exists:
#
#	<depends_type>	<pattern>	<pkg>
#
# "pkg" is the match for "pattern" used to fulfill the dependency.
#
_DEPENDS_FILE=	${WRKDIR}/.depends
_RDEPENDS_FILE=	${WRKDIR}/.rdepends

_FULL_DEPENDS_CMD=	\
	${AWK} '$$1 == "full" { print $$3; }' < ${_RDEPENDS_FILE}

_REDUCE_DEPENDS_CMD=	${SETENV} CAT=${CAT:Q}				\
				PKG_ADMIN=${PKG_ADMIN_CMD:Q}		\
				PWD_CMD=${PWD_CMD:Q} TEST=${TEST:Q}	\
			${AWK} -f ${PKGSRCDIR}/mk/flavor/pkg/reduce-depends.awk

_flavor-show-depends: .PHONY
	@case ${VARNAME:Q}"" in						\
	BUILD_DEPENDS)	${_REDUCE_DEPENDS_CMD} ${BUILD_DEPENDS:Q} ;;	\
	DEPENDS|*)	${_REDUCE_DEPENDS_CMD} ${DEPENDS:Q} ;;		\
	esac

_LIST_DEPENDS_CMD=	\
	${SETENV} AWK=${AWK:Q} PKG_ADMIN=${PKG_ADMIN:Q} \
		PKGSRCDIR=${PKGSRCDIR:Q} PWD_CMD=${PWD_CMD:Q} SED=${SED:Q} \
		${SH} ${PKGSRCDIR}/mk/flavor/pkg/list-dependencies \
			" "${BOOTSTRAP_DEPENDS:Q} \
			" "${BUILD_DEPENDS:Q} \
			" "${DEPENDS:Q}

_LIST_DEPENDS_CMD.bootstrap=	\
	${SETENV} AWK=${AWK:Q} PKG_ADMIN=${PKG_ADMIN:Q} \
		PKGSRCDIR=${PKGSRCDIR:Q} PWD_CMD=${PWD_CMD:Q} SED=${SED:Q} \
		${SH} ${PKGSRCDIR}/mk/flavor/pkg/list-dependencies \
			" "${BOOTSTRAP_DEPENDS:Q} " " " "

_RESOLVE_DEPENDS_CMD=	\
	${SETENV} _PKG_DBDIR=${_PKG_DBDIR:Q} PKG_ADMIN=${PKG_ADMIN:Q} \
		_DEPENDS_FILE=${_DEPENDS_FILE:Q} \
		${SH} ${PKGSRCDIR}/mk/flavor/pkg/resolve-dependencies \
			" "${BOOTSTRAP_DEPENDS:Q} \
			" "${BUILD_DEPENDS:Q} \
			" "${DEPENDS:Q}

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
		silent=${_BOOTSTRAP_VERBOSE:Dyes};			\
		if ${TEST} -z "$${silent}"; then			\
			${STEP_MSG} "Required installed package $$pattern: $$pkg found"; \
		fi;							\
		;;							\
	esac

${_DEPENDS_FILE}:
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${_LIST_DEPENDS_CMD} > ${.TARGET}

${_RDEPENDS_FILE}: ${_DEPENDS_FILE}
	${RUN} ${_RESOLVE_DEPENDS_CMD} > ${.TARGET}

# _flavor-install-dependencies:
#	Installs any missing dependencies.
#
_flavor-install-dependencies: .PHONY ${_DEPENDS_FILE}
	${RUN}								\
	exec 3<&0;							\
	${CAT} ${_DEPENDS_FILE} | 					\
	while read type pattern dir; do					\
		${TEST} "$$type" = "bootstrap" && continue;		\
		${_DEPENDS_INSTALL_CMD} 0<&3;				\
	done

# _flavor-post-install-dependencies:
#	Targets after installing all dependencies.
#
_flavor-post-install-dependencies: .PHONY ${_RDEPENDS_FILE}

######################################################################
### bootstrap-depends (PUBLIC, pkgsrc/mk/depends/depends.mk)
######################################################################
### bootstrap-depends is a public target to install any missing
### dependencies needed during stages before the normal "depends"
### stage.  These dependencies are listed in BOOTSTRAP_DEPENDS.
###
.PHONY: bootstrap-depends
_BOOTSTRAP_DEPENDS_TARGETS+=	acquire-bootstrap-depends-lock
_BOOTSTRAP_DEPENDS_TARGETS+=	_flavor-bootstrap-depends
_BOOTSTRAP_DEPENDS_TARGETS+=	release-bootstrap-depends-lock

bootstrap-depends: ${_BOOTSTRAP_DEPENDS_TARGETS}

.PHONY: _flavor-bootstrap-depends
_flavor-bootstrap-depends:
	${RUN}${_LIST_DEPENDS_CMD.bootstrap} | 				\
	while read type pattern dir; do					\
		${TEST} "$$type" != "bootstrap" && continue;		\
		${_DEPENDS_INSTALL_CMD};				\
	done

.PHONY:
acquire-bootstrap-depends-lock: acquire-lock
release-bootstrap-depends-lock: release-lock
