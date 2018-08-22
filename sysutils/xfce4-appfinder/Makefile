# $NetBSD: Makefile,v 1.47 2018/08/22 09:46:42 wiz Exp $

PKGREVISION= 1
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
