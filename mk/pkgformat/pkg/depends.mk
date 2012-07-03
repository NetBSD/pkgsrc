# $NetBSD: depends.mk,v 1.1.6.1 2012/07/03 23:24:24 tron Exp $

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
# ${_RRDEPENDS_FILE} is like ${_RPDENDS_FILE}, but all build dependencies
# are dropped, if they are dependencies of one of the full dependencies.
#
_DEPENDS_FILE=	${WRKDIR}/.depends
_RDEPENDS_FILE=	${WRKDIR}/.rdepends

_RRDEPENDS_FILE=${WRKDIR}/.rrdepends

_FULL_DEPENDS_CMD=	\
	${AWK} '$$1 == "full" { print $$3; }' < ${_RDEPENDS_FILE}

_REDUCE_DEPENDS_CMD=	${PKGSRC_SETENV} CAT=${CAT:Q}				\
				PKG_ADMIN=${PKG_ADMIN_CMD:Q}		\
				PWD_CMD=${PWD_CMD:Q} TEST=${TEST:Q}	\
			${AWK} -f ${PKGSRCDIR}/mk/pkgformat/pkg/reduce-depends.awk

_REDUCE_RESOLVED_DEPENDS_CMD=${PKGSRC_SETENV} CAT=${CAT:Q}		\
				PKG_INFO=${PKG_INFO_CMD:Q}		\
			${AWK} -f ${PKGSRCDIR}/mk/pkgformat/pkg/reduce-resolved-depends.awk \
				< ${_RDEPENDS_FILE}

_pkgformat-show-depends: .PHONY
	@case ${VARNAME:Q}"" in						\
	BUILD_DEPENDS)	${_REDUCE_DEPENDS_CMD} ${BUILD_DEPENDS:Q} ;;	\
	DEPENDS|*)	${_REDUCE_DEPENDS_CMD} ${DEPENDS:Q} ;;		\
	esac

_LIST_DEPENDS_CMD=	\
	${PKGSRC_SETENV} AWK=${AWK:Q} PKG_ADMIN=${PKG_ADMIN:Q} \
		PKGSRCDIR=${PKGSRCDIR:Q} PWD_CMD=${PWD_CMD:Q} SED=${SED:Q} \
		${SH} ${PKGSRCDIR}/mk/pkgformat/pkg/list-dependencies \
			" "${BOOTSTRAP_DEPENDS:Q} \
			" "${BUILD_DEPENDS:Q} \
			" "${DEPENDS:Q}

_LIST_DEPENDS_CMD.bootstrap=	\
	${PKGSRC_SETENV} AWK=${AWK:Q} PKG_ADMIN=${PKG_ADMIN:Q} \
		PKGSRCDIR=${PKGSRCDIR:Q} PWD_CMD=${PWD_CMD:Q} SED=${SED:Q} \
		${SH} ${PKGSRCDIR}/mk/pkgformat/pkg/list-dependencies \
			" "${BOOTSTRAP_DEPENDS:Q} " " " "

_RESOLVE_DEPENDS_CMD=	\
	${PKGSRC_SETENV} _PKG_DBDIR=${_PKG_DBDIR:Q} PKG_INFO=${PKG_INFO:Q} \
		_DEPENDS_FILE=${_DEPENDS_FILE:Q} \
		${SH} ${PKGSRCDIR}/mk/pkgformat/pkg/resolve-dependencies \
			" "${BOOTSTRAP_DEPENDS:Q} \
			" "${BUILD_DEPENDS:Q} \
			" "${DEPENDS:Q}

# _DEPENDS_INSTALL_CMD checks whether the package $pattern is installed,
#	and installs it if necessary.
#
#	@param $pattern The pattern of the package to be installed.
#	@param $dir The pkgsrc directory from which the package can be
#		built.
#	@param $type The dependency type. Can be one of bootstrap,
#		build, full.
#
_DEPENDS_INSTALL_CMD=							\
	pkg=`${_PKG_BEST_EXISTS} "$$pattern" || ${TRUE}`;		\
	case $$type in bootstrap) Type=Bootstrap;; build) Type=Build;; full) Type=Full;; esac; \
	case "$$pkg" in							\
	"")								\
		${STEP_MSG} "$$Type dependency $$pattern: NOT found";	\
		target=${DEPENDS_TARGET:Q};				\
		${STEP_MSG} "Verifying $$target for $$dir";		\
		[ -d "$$dir" ] || ${FAIL_MSG} "[depends.mk] The directory \`\`$$dir'' does not exist."; \
		cd $$dir;						\
		${PKGSRC_SETENV} ${PKGSRC_MAKE_ENV} _PKGSRC_DEPS=" ${PKGNAME}${_PKGSRC_DEPS}" PKGNAME_REQD="$$pattern" ${MAKE} ${MAKEFLAGS} _AUTOMATIC=yes $$target; \
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
			${STEP_MSG} "$$Type dependency $$pattern: found $$pkg"; \
		fi;							\
		;;							\
	esac

${_DEPENDS_FILE}:
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${_LIST_DEPENDS_CMD} > ${.TARGET}

${_RDEPENDS_FILE}: ${_DEPENDS_FILE}
	${RUN} ${_RESOLVE_DEPENDS_CMD} > ${.TARGET}

${_RRDEPENDS_FILE}: ${_RDEPENDS_FILE}
	${RUN} ${_REDUCE_RESOLVED_DEPENDS_CMD} > ${.TARGET}

# _pkgformat-install-dependencies:
#	Installs any missing dependencies.
#
_pkgformat-install-dependencies: .PHONY ${_DEPENDS_FILE}
	${RUN}								\
	exec 3<&0;							\
	${CAT} ${_DEPENDS_FILE} | 					\
	while read type pattern dir; do					\
		${TEST} "$$type" != "bootstrap" || continue;		\
		${_DEPENDS_INSTALL_CMD} 0<&3;				\
	done

# _pkgformat-post-install-dependencies:
#	Targets after installing all dependencies.
#
_pkgformat-post-install-dependencies: .PHONY ${_RDEPENDS_FILE} ${_RRDEPENDS_FILE}

######################################################################
### pkg_install-depends (PUBLIC, pkgsrc/mk/depends/depends.mk)
######################################################################
### pkg_install-depends is a public target to install or update
### pkg_install itself.
###
.PHONY: pkg_install-depends
pkg_install-depends:
	${RUN}if [ `${PKG_INFO_CMD} -V 2>/dev/null || echo 20010302` -lt ${PKGTOOLS_REQD} ]; then \
	${PHASE_MSG} "Trying to handle out-dated pkg_install..."; \
	cd ../../pkgtools/pkg_install && ${PKGSRC_SETENV} ${PKGSRC_MAKE_ENV} \
	    _PKGSRC_DEPS=" ${PKGNAME}${_PKGSRC_DEPS}" \
	    ${MAKE} ${MAKEFLAGS} _AUTOMATIC=yes clean && \
	cd ../../pkgtools/pkg_install && ${PKGSRC_SETENV} ${PKGSRC_MAKE_ENV} \
	    _PKGSRC_DEPS=" ${PKGNAME}${_PKGSRC_DEPS}" \
	    ${MAKE} ${MAKEFLAGS} _AUTOMATIC=yes ${DEPENDS_TARGET:Q}; \
	fi

######################################################################
### bootstrap-depends (PUBLIC, pkgsrc/mk/depends/depends.mk)
######################################################################
### bootstrap-depends is a public target to install any missing
### dependencies needed during stages before the normal "depends"
### stage.  These dependencies are listed in BOOTSTRAP_DEPENDS.
###
.PHONY: bootstrap-depends
_BOOTSTRAP_DEPENDS_TARGETS+=	acquire-bootstrap-depends-lock
_BOOTSTRAP_DEPENDS_TARGETS+=	_pkgformat-bootstrap-depends
_BOOTSTRAP_DEPENDS_TARGETS+=	release-bootstrap-depends-lock

bootstrap-depends: ${_BOOTSTRAP_DEPENDS_TARGETS}

.PHONY: _pkgformat-bootstrap-depends
.if empty(PKG_FAIL_REASON)
_pkgformat-bootstrap-depends:
	${RUN}${_LIST_DEPENDS_CMD.bootstrap} | 				\
	while read type pattern dir; do					\
		${TEST} "$$type" = "bootstrap" || continue;		\
		${_DEPENDS_INSTALL_CMD};				\
	done
.else
_pkgformat-bootstrap-depends:
	${RUN}${DO_NADA}
.endif

.PHONY:
acquire-bootstrap-depends-lock: acquire-lock
release-bootstrap-depends-lock: release-lock
