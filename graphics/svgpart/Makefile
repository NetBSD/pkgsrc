# $NetBSD: Makefile,v 1.57 2021/04/07 12:28:25 markd Exp $

DISTNAME=	svgpart-${KAPPSVER}
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	KDE svg part
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
