# $NetBSD: Makefile,v 1.74 2023/05/06 19:08:50 ryoon Exp $

DISTNAME=	kdegraphics-mobipocket-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	Library to support mobipocket ebooks
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
