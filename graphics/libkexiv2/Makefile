# $NetBSD: Makefile,v 1.117 2026/09/27 11:36:52 tnn Exp $

DISTNAME=	libkexiv2-${KAPPSVER}
PKGREVISION=	1
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
