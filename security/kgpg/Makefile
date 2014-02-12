# $NetBSD: Makefile,v 1.28 2014/02/12 23:18:33 tron Exp $

DISTNAME=	kgpg-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	security
COMMENT=	KDE encryption tool

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
