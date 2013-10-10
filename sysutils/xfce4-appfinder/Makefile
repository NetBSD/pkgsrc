# $NetBSD: Makefile,v 1.35 2013/10/10 14:42:33 ryoon Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-appfinder-${XFCE4_VERSION}
PKGREVISION=	22
CATEGORIES=	sysutils
COMMENT=	Xfce application finder

.include "../../devel/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4menu/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
