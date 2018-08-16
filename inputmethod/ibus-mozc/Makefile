# $NetBSD: Makefile,v 1.44 2018/08/16 18:54:56 adam Exp $

PKGNAME=	ibus-${DISTNAME}
PKGREVISION=	8

INSTALLATION_DIRS+=	libexec share/ibus share/ibus/component \
			share/ibus-mozc

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	mozc-renderer-[0-9]*:../../inputmethod/mozc-renderer
DEPENDS+=	mozc-server-[0-9]*:../../inputmethod/mozc-server
DEPENDS+=	mozc-tool-[0-9]*:../../inputmethod/mozc-tool

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c ${MOZC_BUILD_MODE} \
			unix/ibus/ibus.gyp:ibus_mozc_lib \
			unix/ibus/ibus.gyp:ibus_mozc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/ibus_mozc \
		${DESTDIR}${PREFIX}/libexec/ibus-engine-mozc
	${INSTALL_DATA} ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/gen/unix/ibus/mozc.xml \
		${DESTDIR}${PREFIX}/share/ibus/component
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DESTDIR}${PREFIX}/share/ibus-mozc/product_icon.png

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/mozc-server/Makefile.common"
