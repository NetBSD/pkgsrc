# $NetBSD: Makefile,v 1.8 2012/09/15 10:06:15 obache Exp $

DISTNAME=	kgpg-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	security
COMMENT=	KDE encryption tool

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
