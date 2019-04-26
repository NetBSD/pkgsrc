# $NetBSD: build.mk,v 1.8 2019/04/26 13:13:52 maya Exp $

BUILD_DEPENDS+=	${PYPKGPREFIX}-meson-[0-9]*:../../devel/py-meson

.PHONY: meson-configure meson-build meson-install

do-configure: meson-configure
meson-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} meson --prefix ${PREFIX} --libdir lib --mandir ${PKGMANDIR} --buildtype=plain ${MESON_ARGS} . output

do-build: meson-build
meson-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ninja -C output

do-install: meson-install
meson-install:
	if [ -f ${WRKSRC}/meson_post_install.py ]; then		\
		${CHMOD} +x ${WRKSRC}/meson_post_install.py;	\
	fi
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ninja -C output install

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
