# $NetBSD: build.mk,v 1.2 2019/10/05 20:09:52 nia Exp $

BUILD_DEPENDS+=	meson-[0-9]*:../../devel/meson

CONFIGURE_DIRS?=	.
BUILD_DIRS?=		${CONFIGURE_DIRS}
INSTALL_DIRS?=		${CONFIGURE_DIRS}

.PHONY: meson-configure meson-build meson-install

# pkgsrc contains multiple llvm-config executables at multiple locations.
.if !empty(LLVM_CONFIG_PATH)
MAKE_ENV+=	LLVM_CONFIG_PATH=${LLVM_CONFIG_PATH:Q}
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

.include "../../lang/python/application.mk"
