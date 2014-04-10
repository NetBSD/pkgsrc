# $NetBSD: Makefile,v 1.7 2014/04/10 06:21:36 obache Exp $

DISTNAME=	kuser-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	sysutils
COMMENT=	KDE user manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
