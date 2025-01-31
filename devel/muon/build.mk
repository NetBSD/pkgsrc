# $NetBSD: build.mk,v 1.1 2025/01/31 17:11:10 micha Exp $

# Based on devel/meson/build.mk without the cross-compilation stuff
# (cross-compilation is not supported by muon).
# Uses devel/samurai as build tool (instead of devel/ninja-build).

MUON_REQD?=	0.3
.for version in ${MUON_REQD}
TOOL_DEPENDS+=	muon>=${version}:../../devel/muon
.endfor

CONFIGURE_DIRS?=	.
BUILD_DIRS?=		${CONFIGURE_DIRS}
INSTALL_DIRS?=		${CONFIGURE_DIRS}
TEST_DIRS?=		${CONFIGURE_DIRS}

.PHONY: muon-configure muon-build muon-install muon-test

# pkgsrc contains multiple llvm-config executables at multiple locations.
.if !empty(LLVM_CONFIG_PATH)
MAKE_ENV+=	LLVM_CONFIG_PATH=${LLVM_CONFIG_PATH:Q}
.endif

.include "../../mk/bsd.prefs.mk"

do-configure: muon-configure
muon-configure:
.for d in ${CONFIGURE_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${MAKE_ENV} muon setup \
		-Dprefix=${PREFIX} \
		-Dlibdir=lib \
		-Dlibexecdir=libexec \
		-Dmandir=${PKGMANDIR} \
		-Dsysconfdir=${PKG_SYSCONFDIR} \
		-Dbuildtype=plain \
		${MUON_ARGS} \
		output
.endfor

do-build: muon-build
muon-build:
.for d in ${BUILD_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${MAKE_ENV} \
		samu -j ${_MAKE_JOBS_N:U1} -C output
.endfor

do-install: muon-install
muon-install:
.for d in ${INSTALL_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		muon -C output install
.endfor

do-test: muon-test
muon-test:
.for d in ${TEST_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${TEST_ENV} \
		muon -C output test
.endfor

_VARGROUPS+=		muon
_PKG_VARS.muon=		MUON_REQD
_PKG_VARS.muon+=	CONFIGURE_DIRS
_PKG_VARS.muon+=	BUILD_DIRS MAKE_ENV
_PKG_VARS.muon+=	TEST_DIRS TEST_ENV
_PKG_VARS.muon+=	INSTALL_DIRS INSTALL_ENV
_PKG_VARS.muon+=	LLVM_CONFIG_PATH
_PKG_VARS.muon+=	MUON_ARGS
_USER_VARS.muon=	MAKE_JOBS PKG_SYSCONFDIR
_USE_VARS.muon=		WRKSRC PREFIX PKGMANDIR
_USE_VARS.muon+=	_MAKE_JOBS_N
_DEF_VARS.muon=		TOOL_DEPENDS
_LISTED_VARS.muon=	*_ARGS *_DEPENDS
_SORTED_VARS.muon=	*_ENV
