# $NetBSD: Makefile,v 1.23 2023/11/12 13:22:25 wiz Exp $

PKGNAME=	${DISTNAME:S/fcitx-/fcitx5-/}
PKGREVISION=	22

INSTALLATION_DIRS+=	lib/fcitx5
INSTALLATION_DIRS+=	share/fcitx5/addon
INSTALLATION_DIRS+=	share/fcitx5/inputmethod
.for lang in ca da de he ja ko ru zh_CN zh_TW
INSTALLATION_DIRS+=	share/locale/${lang}/LC_MESSAGES
.endfor
INSTALLATION_DIRS+=	share/metainfo
.for size in 128x128 32x32 48x48
INSTALLATION_DIRS+=	share/icons/hicolor/${size}/apps
.endfor

USE_TOOLS+=	bash

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	mozc-server-[0-9]*:../../inputmethod/mozc-server
DEPENDS+=	mozc-tool-[0-9]*:../../inputmethod/mozc-tool

pre-configure:
	# Do not fail by fcitx4 is not found.
	${RM} ${WRKSRC}/unix/fcitx/fcitx.gyp

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c ${MOZC_BUILD_MODE} \
			unix/fcitx5/fcitx5.gyp:fcitx5-mozc

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		OSDEST=${OSDEST} _bldtype=${MOZC_BUILD_MODE} \
		${BASH} ../scripts/install_fcitx5

.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../inputmethod/fcitx5-mozc/Makefile.common"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
