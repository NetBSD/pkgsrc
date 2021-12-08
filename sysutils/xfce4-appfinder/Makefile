# $NetBSD: Makefile,v 1.64 2021/12/08 16:06:40 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-appfinder-4.16.1
CATEGORIES=	sysutils
MASTER_SITES+=	https://archive.xfce.org/src/xfce/xfce4-appfinder/4.16/

HOMEPAGE=	https://docs.xfce.org/xfce/xfce4-appfinder/start
COMMENT=	Xfce application finder

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
