# $NetBSD: Makefile,v 1.105 2026/01/07 08:47:22 wiz Exp $

DISTNAME=	libkdcraw-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	KDE digital camera raw image library wrapper
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DQT_MAJOR_VERSION=6

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.18.0
.include "../../graphics/libraw/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
