# $NetBSD: build.mk,v 1.5 2020/02/25 04:54:35 rillig Exp $

BUILD_DEPENDS+=	meson-[0-9]*:../../devel/meson

CONFIGURE_DIRS?=	.
BUILD_DIRS?=		${CONFIGURE_DIRS}
INSTALL_DIRS?=		${CONFIGURE_DIRS}
TEST_DIRS?=		${CONFIGURE_DIRS}

.PHONY: meson-configure meson-build meson-install meson-test

# pkgsrc contains multiple llvm-config executables at multiple locations.
.if !empty(LLVM_CONFIG_PATH)
MAKE_ENV+=	LLVM_CONFIG_PATH=${LLVM_CONFIG_PATH:Q}
.endif

.if !defined(USE_CMAKE)
MAKE_ENV+=	CMAKE=${TOOLS_PATH.false}
.endif

do-configure: meson-configure
meson-configure:
.for d in ${CONFIGURE_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${MAKE_ENV} meson \
		--prefix ${PREFIX} --libdir lib --mandir ${PKGMANDIR} \
		--sysconfdir ${PKG_SYSCONFDIR} --buildtype=plain ${MESON_ARGS} . output
.endfor

do-build: meson-build
meson-build:
.for d in ${BUILD_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${MAKE_ENV} ninja -j ${MAKE_JOBS:U1} -C output
.endfor

do-install: meson-install
meson-install:
.for d in ${INSTALL_DIRS}
	if [ -f ${WRKSRC}/meson_post_install.py ]; then		\
		${CHMOD} +x ${WRKSRC}/meson_post_install.py;	\
	fi
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ninja -C output install
.endfor

do-test: meson-test
meson-test:
.for d in ${TEST_DIRS}
	cd ${WRKSRC} && cd ${d} && ${SETENV} ${TEST_ENV} ninja -C output test
.endfor

.include "../../lang/python/application.mk"

_VARGROUPS+=		meson
_PKG_VARS.meson=	CONFIGURE_DIRS
_PKG_VARS.meson+=	BUILD_DIRS MAKE_ENV
_PKG_VARS.meson+=	TEST_DIRS TEST_ENV
_PKG_VARS.meson+=	INSTALL_DIRS INSTALL_ENV
_PKG_VARS.meson+=	LLVM_CONFIG_PATH
_PKG_VARS.meson+=	USE_CMAKE MESON_ARGS
_USER_VARS.meson=	MAKE_JOBS PKG_SYSCONFDIR
_USE_VARS.meson=	TOOLS_PATH.false WRKSRC PREFIX PKGMANDIR
_DEF_VARS.meson=	BUILD_DEPENDS
_LISTED_VARS.meson=	*_ARGS *_DEPENDS
_SORTED_VARS.meson=	*_ENV
