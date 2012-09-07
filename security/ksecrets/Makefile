# $NetBSD: Makefile,v 1.5 2012/09/07 19:17:27 adam Exp $

DISTNAME=	ksecrets-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	security
COMMENT=	KDE secrets service

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
