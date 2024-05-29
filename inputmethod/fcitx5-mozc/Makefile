# $NetBSD: Makefile,v 1.29 2024/05/29 16:33:08 adam Exp $

PKGNAME=	fcitx5-${DISTNAME}
PKGREVISION=	2

INSTALLATION_DIRS+=	lib/fcitx5
INSTALLATION_DIRS+=	share/fcitx5/addon
INSTALLATION_DIRS+=	share/fcitx5/inputmethod
.for lang in ca da de he ja ko ru tr zh_CN zh_TW
INSTALLATION_DIRS+=	share/locale/${lang}/LC_MESSAGES
.endfor
INSTALLATION_DIRS+=	share/metainfo
.for size in 128x128 32x32 48x48
INSTALLATION_DIRS+=	share/icons/hicolor/${size}/apps
.endfor

USE_TOOLS+=	bash

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	mozc-server>=2.29:../../inputmethod/mozc-server
DEPENDS+=	mozc-renderer>=2.29:../../inputmethod/mozc-renderer
DEPENDS+=	mozc-tool>=2.29:../../inputmethod/mozc-tool

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/bazel \
			--output_user_root=${WRKDIR}/bazel \
			--client_debug \
			build \
			unix/fcitx5:fcitx5-mozc.so \
			--host_action_env=CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR} \
			--action_env=CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR} \
			--host_action_env=PATH=${PATH} \
			--action_env=PATH=${PATH} \
			--sandbox_debug \
			--verbose_failures \
			--config oss_linux --compilation_mode opt


do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		${BASH} ../scripts/install_fcitx5_bazel
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		${BASH} ../scripts/install_fcitx5_data
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		${BASH} ../scripts/install_fcitx5_icons

.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../inputmethod/fcitx5-mozc/Makefile.common"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../mk/bsd.pkg.mk"
