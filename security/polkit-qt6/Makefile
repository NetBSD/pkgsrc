# $NetBSD: Makefile,v 1.2 2024/05/29 16:34:19 adam Exp $

DISTNAME=	polkit-qt-1-0.200.0
PKGNAME=	${DISTNAME:S/-qt-1-/-qt6-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://invent.kde.org/libraries/polkit-qt-1/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invent.kde.org/libraries/polkit-qt-1
COMMENT=	Qt6 Wrapper around PolicyKit
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/polkit-qt-1-v0.200.0-aa1c6c414ec021fd32e30492c00bb13347e228db

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DQT_MAJOR_VERSION=6

PKGCONFIG_OVERRIDE+=	polkit-qt6-1.pc.cmake polkit-qt6-agent-1.pc.cmake
PKGCONFIG_OVERRIDE+=	polkit-qt6-core-1.pc.cmake polkit-qt6-gui-1.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
