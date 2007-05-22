# $NetBSD: depends.mk,v 1.30 2007/05/22 21:27:59 joerg Exp $

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

_RESOLVE_DEPENDS_CMD=	\
	${SETENV} _PKG_DBDIR=${_PKG_DBDIR:Q} PKG_ADMIN=${PKG_ADMIN:Q} \
		_DEPENDS_FILE=${_DEPENDS_FILE:Q} \
		${SH} ${PKGSRCDIR}/mk/flavor/pkg/resolve-dependencies \
			" "${BOOTSTRAP_DEPENDS:Q} \
			" "${BUILD_DEPENDS:Q} \
			" "${DEPENDS:Q}

_INSTALL_DEPENDS=	${PKGSRCDIR}/mk/flavor/pkg/install-dependencies
.for _var in _PKG_DBDIR _PKGSR_DEPS _DEPENDS_FILE DEPENDS_TARGET \
	MAKE MAKEFLAGS OBJECT_FMT PKG_ADMIN PKG_INFO PKGNAME \
	PKGSRC_MAKE_ENV SETENV
_INSTALL_DEPENDS_ARGS+=	${_var}=${${_var}:Q:Q}
.endfor

${_DEPENDS_FILE}:
	${RUN} ${MKDIR} ${.TARGET:H}
	${RUN} ${_LIST_DEPENDS_CMD} > ${.TARGET}

${_RDEPENDS_FILE}: ${_DEPENDS_FILE}
	${RUN} ${_RESOLVE_DEPENDS_CMD} > ${.TARGET}

# _flavor-install-dependencies:
#	Installs any missing dependencies.
#
_flavor-install-dependencies: .PHONY ${_DEPENDS_FILE}
	${RUN}${SH} ${_INSTALL_DEPENDS} no-bootstrap ${_INSTALL_DEPENDS_ARGS}

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
_BOOTSTRAP_DEPENDS_TARGETS+=	${_DEPENDS_FILE}
_BOOTSTRAP_DEPENDS_TARGETS+=	release-bootstrap-depends-lock

bootstrap-depends: ${_BOOTSTRAP_DEPENDS_TARGETS}
	${RUN}${SH} ${_INSTALL_DEPENDS} bootstrap ${_INSTALL_DEPENDS_ARGS}

.PHONY: 
acquire-bootstrap-depends-lock: acquire-lock
release-bootstrap-depends-lock: release-lock
