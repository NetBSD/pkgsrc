# $NetBSD: Makefile,v 1.11 2012/12/16 01:52:32 obache Exp $

DISTNAME=	kgpg-${_KDE_VERSION}
PKGREVISION=	7
CATEGORIES=	security
COMMENT=	KDE encryption tool

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
