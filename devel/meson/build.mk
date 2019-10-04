# $NetBSD: build.mk,v 1.1 2019/10/04 14:06:18 prlw1 Exp $

BUILD_DEPENDS+=	meson-[0-9]*:../../devel/meson

.PHONY: meson-configure meson-build meson-install

# pkgsrc contains multiple llvm-config executables at multiple locations.
.if !empty(LLVM_CONFIG_PATH)
MAKE_ENV+=	LLVM_CONFIG_PATH=${LLVM_CONFIG_PATH:Q}
.endif

do-configure: meson-configure
meson-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} meson --prefix ${PREFIX} --libdir lib --mandir ${PKGMANDIR} --sysconfdir ${PKG_SYSCONFDIR} --buildtype=plain ${MESON_ARGS} . output

do-build: meson-build
meson-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ninja -j ${MAKE_JOBS:U1} -C output

do-install: meson-install
meson-install:
	if [ -f ${WRKSRC}/meson_post_install.py ]; then		\
		${CHMOD} +x ${WRKSRC}/meson_post_install.py;	\
	fi
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ninja -C output install

.include "../../lang/python/application.mk"
