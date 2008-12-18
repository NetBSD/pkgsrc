# $NetBSD: Makefile,v 1.10 2008/12/18 14:23:52 hira Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-appfinder-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
COMMENT=	Xfce application finder

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
