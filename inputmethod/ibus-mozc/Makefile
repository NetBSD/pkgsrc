# $NetBSD: Makefile,v 1.24 2015/09/23 11:53:27 joerg Exp $

PKGNAME=	ibus-${DISTNAME}

INSTALLATION_DIRS+=	libexec share/ibus share/ibus/component \
			share/ibus-mozc

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	mozc-renderer-[0-9]*:../../inputmethod/mozc-renderer
DEPENDS+=	mozc-server-[0-9]*:../../inputmethod/mozc-server
DEPENDS+=	mozc-tool-[0-9]*:../../inputmethod/mozc-tool

# ../../session/key_info_util.cc:43:10: fatal error: 'protocol/commands.pb.h' file not found
MAKE_JOBS_SAFE=	no

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c ${MOZC_BUILD_MODE} ${_MAKE_JOBS} \
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
