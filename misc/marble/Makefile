# $NetBSD: Makefile,v 1.10 2013/02/06 23:21:33 jperkin Exp $

DISTNAME=	marble-${_KDE_VERSION}
PKGREVISION=	6
CATEGORIES=	misc
COMMENT=	KDE desktop globe

MAKE_JOBS_SAFE=	NO

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
