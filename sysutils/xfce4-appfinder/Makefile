# $NetBSD: Makefile,v 1.78 2024/12/27 08:20:41 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-appfinder-4.20.0
CATEGORIES=	sysutils
MASTER_SITES+=	https://archive.xfce.org/src/xfce/xfce4-appfinder/${PKGVERSION_NOREV:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/xfce4-appfinder/start
COMMENT=	Xfce application finder

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
