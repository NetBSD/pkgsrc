# $NetBSD: Makefile,v 1.39 2016/08/03 10:23:25 adam Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-appfinder-${XFCE4_VERSION}
CATEGORIES=	sysutils

HOMEPAGE=	http://docs.xfce.org/xfce/xfce4-appfinder/start
COMMENT=	Xfce application finder

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
