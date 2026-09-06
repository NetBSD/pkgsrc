# $NetBSD: Makefile,v 1.116 2026/09/06 11:02:53 markd Exp $

DISTNAME=	libkexiv2-${KAPPSVER}
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	KDE wrapper around exiv2
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

USE_CXX_FEATURES+=	filesystem

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DQT_MAJOR_VERSION=6

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
