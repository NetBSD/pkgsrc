# $NetBSD: Makefile,v 1.97 2024/05/29 16:32:59 adam Exp $

DISTNAME=	libkdcraw-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	KDE digital camera raw image library wrapper
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.libraw+=	libraw>=0.18.0
.include "../../graphics/libraw/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
