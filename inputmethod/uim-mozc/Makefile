# $NetBSD: Makefile,v 1.28 2018/11/12 03:52:25 ryoon Exp $

PKGNAME=	uim-${DISTNAME}
PKGREVISION=	9

CONFLICTS+=	ibus-mozc<=1.13.1651.102

INSTALLATION_DIRS+=	lib/uim/plugin share/uim/pixmaps

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	mozc-renderer-[0-9]*:../../inputmethod/mozc-renderer
DEPENDS+=	mozc-server-[0-9]*:../../inputmethod/mozc-server
DEPENDS+=	mozc-tool-[0-9]*:../../inputmethod/mozc-tool

SUBST_CLASSES+=			mozc_tool
SUBST_STAGE.mozc_tool=		pre-configure
SUBST_MESSAGE.mozc_tool=	Fixing mozc_tool path
SUBST_FILES.mozc_tool=		scm/mozc-custom.scm
SUBST_SED.mozc_tool=		-e 's,/usr/lib/mozc/mozc_tool,${PREFIX}/libexec/mozc_tool,g'

post-extract:
	mv ${WRKDIR}/${UIM_MOZC}/uim ${WRKSRC}/unix
	mv ${WRKDIR}/${UIM_MOZC}/scm ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c ${MOZC_BUILD_MODE} \
			unix/uim/uim.gyp:uim-mozc \
			renderer/renderer.gyp:mozc_renderer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/libuim-mozc.so \
		${DESTDIR}${PREFIX}/lib/uim/plugin
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DESTDIR}${PREFIX}/share/uim/pixmaps/mozc.png
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ui-tool.png \
		${DESTDIR}${PREFIX}/share/uim/pixmaps/mozc_tool_selector.png
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ui-properties.png \
		${DESTDIR}${PREFIX}/share/uim/pixmaps/mozc_tool_config_dialog.png
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ui-dictionary.png \
		${DESTDIR}${PREFIX}/share/uim/pixmaps/mozc_tool_dictionary_tool.png
	${INSTALL_DATA} ${WRKSRC}/scm/mozc-custom.scm \
		${DESTDIR}${PREFIX}/share/uim
	${INSTALL_DATA} ${WRKSRC}/scm/mozc-key-custom.scm \
		${DESTDIR}${PREFIX}/share/uim
	${INSTALL_DATA} ${WRKSRC}/scm/mozc.scm \
		${DESTDIR}${PREFIX}/share/uim

UIM_MODULES=	mozc
.include "../../inputmethod/uim/modules.mk"

.include "../../inputmethod/uim/buildlink3.mk"
.include "../../inputmethod/mozc-server/Makefile.common"
