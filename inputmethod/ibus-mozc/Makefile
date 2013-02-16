# $NetBSD: Makefile,v 1.4 2013/02/16 11:22:41 wiz Exp $
#

PKGNAME=	ibus-${DISTNAME}
PKGREVISION=	2

INSTALLATION_DIRS+=	libexec share/ibus share/icons share/ibus/component \
			share/ibus-mozc

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c Release ${_MAKE_JOBS} \
			unix/ibus/ibus.gyp:ibus_mozc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/Release/ibus_mozc \
		${DESTDIR}${PREFIX}/libexec/ibus-engine-mozc
	${INSTALL_DATA} ${WRKSRC}/out_${OSDEST}/Release/obj/gen/unix/ibus/mozc.xml \
		${DESTDIR}${PREFIX}/share/ibus/component
.for f in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/${f}.png \
		${DESTDIR}${PREFIX}/share/icons/${f:S/^ui-/mozc-/}.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/data/images/product_icon_32bpp-128.png \
		${DESTDIR}${PREFIX}/share/icons/mozc.png
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DESTDIR}${PREFIX}/share/ibus-mozc/product_icon.png

.include "Makefile.common"
