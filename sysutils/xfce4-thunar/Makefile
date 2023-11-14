# $NetBSD: Makefile,v 1.94 2023/11/14 14:02:57 wiz Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	thunar-4.18.7
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/xfce/thunar/${PKGVERSION_NOREV:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/thunar/start
COMMENT=	Xfce file manager

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99

PKGCONFIG_OVERRIDE+=	thunarx/thunarx-3.pc.in

PKG_SYSCONFSUBDIR=	xdg/Thunar
EGDIR=			${XFCE4_EGBASE}/Thunar

MAKE_DIRS+=	${XFCE4_EGBASE} ${PREFIX}/share/xfce4
CONF_FILES=	${EGDIR}/uca.xml ${PKG_SYSCONFDIR}/uca.xml

.include "options.mk"

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
