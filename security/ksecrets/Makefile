# $NetBSD: Makefile,v 1.6.2.1 2012/10/03 12:09:20 spz Exp $

DISTNAME=	ksecrets-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	security
COMMENT=	KDE secrets service

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
