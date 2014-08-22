# $NetBSD: Makefile,v 1.24 2014/08/22 11:24:35 wiz Exp $

DISTNAME=	kolourpaint-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	graphics
COMMENT=	KDE paint program

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
