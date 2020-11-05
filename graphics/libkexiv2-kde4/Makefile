# $NetBSD: Makefile,v 1.10 2020/11/05 09:08:25 ryoon Exp $
#

DISTNAME=	libkexiv2-15.08.3
PKGNAME=	libkexiv2-kde4-15.08.3
PKGREVISION=	9
CATEGORIES=	graphics
COMMENT=	KDE wrapper around exiv2
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=	libkexiv2.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
