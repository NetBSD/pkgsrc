# $NetBSD: Makefile,v 1.67 2023/01/03 17:38:16 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-appfinder-4.18.0
CATEGORIES=	sysutils
MASTER_SITES+=	https://archive.xfce.org/src/xfce/xfce4-appfinder/${PKGVERSION_NOREV:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/xfce4-appfinder/start
COMMENT=	Xfce application finder

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
