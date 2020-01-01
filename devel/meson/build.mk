# $NetBSD: build.mk,v 1.4 2020/01/01 21:15:06 adam Exp $

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
