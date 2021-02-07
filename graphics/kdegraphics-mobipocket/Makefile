# $NetBSD: Makefile,v 1.58 2021/02/07 06:30:08 ryoon Exp $

DISTNAME=	kdegraphics-mobipocket-${KAPPSVER}
PKGREVISION=	6
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	Library to support mobipocket ebooks
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
