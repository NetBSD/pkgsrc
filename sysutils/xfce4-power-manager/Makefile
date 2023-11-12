# $NetBSD: Makefile,v 1.27 2023/11/12 13:23:39 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-power-manager-4.18.2
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/xfce/xfce4-power-manager/${PKGVERSION_NOREV:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfce4-power-manager
COMMENT=	Xfce power manager

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

CONF_FILES=	share/examples/xfce4/autostart/xfce4-power-manager.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/xfce4-power-manager.desktop

.include "../../x11/libXmu/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxfce4ui+=	libxfce4ui>=4.18.2
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../sysutils/consolekit/buildlink3.mk"
.endif
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
