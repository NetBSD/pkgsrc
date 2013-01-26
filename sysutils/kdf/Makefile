# $NetBSD: Makefile,v 1.29 2013/01/26 21:38:53 adam Exp $

DISTNAME=	kdf-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	sysutils
COMMENT=	show mount points and disk usage under KDE desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
