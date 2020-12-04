# $NetBSD: Makefile,v 1.54 2020/12/04 04:55:59 riastradh Exp $

DISTNAME=	svgpart-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	KDE svg part
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
