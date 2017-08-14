# $NetBSD: build.mk,v 1.1 2017/08/14 21:14:10 wiz Exp $

BUILD_DEPENDS+=	${PYPKGPREFIX}-meson-[0-9]*:../../devel/py-meson

.PHONY: meson-configure meson-build meson-install

do-configure: meson-configure
meson-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} meson --prefix ${PREFIX} --buildtype=plain . output

do-build: meson-build
meson-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ninja -C output

do-install: meson-install
meson-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ninja -C output install

.include "../../lang/python/application.mk"
