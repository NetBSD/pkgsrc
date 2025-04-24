# $NetBSD: Makefile,v 1.109 2025/04/24 14:14:29 wiz Exp $

DISTNAME=	libkexiv2-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	KDE wrapper around exiv2
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

USE_CXX_FEATURES+=	filesystem

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	pkg-config

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
