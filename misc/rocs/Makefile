# $NetBSD: Makefile,v 1.4 2012/07/02 13:37:41 adam Exp $

DISTNAME=	rocs-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	KDE graph theory IDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
