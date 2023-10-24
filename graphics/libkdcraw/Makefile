# $NetBSD: Makefile,v 1.92 2023/10/24 22:09:28 wiz Exp $

DISTNAME=	libkdcraw-${KAPPSVER}
PKGREVISION=	1
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
