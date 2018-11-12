# $NetBSD: Makefile,v 1.48 2018/11/12 03:52:57 ryoon Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-appfinder-4.13.0
CATEGORIES=	sysutils
MASTER_SITES+=	http://archive.xfce.org/src/xfce/xfce4-appfinder/4.13/

HOMEPAGE=	http://docs.xfce.org/xfce/xfce4-appfinder/start
COMMENT=	Xfce application finder

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
