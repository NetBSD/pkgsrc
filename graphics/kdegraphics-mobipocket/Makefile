# $NetBSD: Makefile,v 1.96 2026/09/02 19:02:42 wiz Exp $

DISTNAME=	kdegraphics-mobipocket-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/
COMMENT=	Library to support mobipocket ebooks
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

CMAKE_CONFIGURE_ARGS+=	-DQT_MAJOR_VERSION=6

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
