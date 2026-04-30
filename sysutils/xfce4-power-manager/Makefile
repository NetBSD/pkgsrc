# $NetBSD: Makefile,v 1.44 2026/04/30 16:25:58 vins Exp $

PKGREVISION=	8
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-power-manager-4.20.0
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/xfce/xfce4-power-manager/${PKGVERSION_NOREV:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfce4-power-manager
COMMENT=	Xfce power manager

BUILD_DEFS+=	PKG_SYSCONFBASE

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-backend=${LOWER_OPSYS}
.endif
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE} \
			--enable-x11 \
			--with-libintl-prefix=${BUILDLINK_PREFIX.gettext-lib}

.include "options.mk"

CONF_FILES=	share/examples/xfce4/autostart/xfce4-power-manager.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/xfce4-power-manager.desktop

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../sysutils/consolekit/buildlink3.mk"
.endif
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
