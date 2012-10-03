# $NetBSD: Makefile,v 1.26.2.1 2012/10/03 12:09:30 spz Exp $

DISTNAME=	kdf-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	sysutils
COMMENT=	show mount points and disk usage under KDE desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
