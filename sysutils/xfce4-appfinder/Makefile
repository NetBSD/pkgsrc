# $NetBSD: Makefile,v 1.59 2020/03/10 22:11:02 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-appfinder-4.14.0
CATEGORIES=	sysutils
MASTER_SITES+=	http://archive.xfce.org/src/xfce/xfce4-appfinder/4.14/

HOMEPAGE=	https://docs.xfce.org/xfce/xfce4-appfinder/start
COMMENT=	Xfce application finder

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
