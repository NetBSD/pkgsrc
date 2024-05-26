# $NetBSD: Makefile,v 1.36 2024/05/26 10:46:25 markd Exp $

DISTNAME=	polkit-qt-1-0.200.0
PKGNAME=	${DISTNAME:S/-qt-1-/-qt5-/}
CATEGORIES=	security
MASTER_SITES=	https://invent.kde.org/libraries/polkit-qt-1/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invent.kde.org/libraries/polkit-qt-1
COMMENT=	Qt5 Wrapper around PolicyKit
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/polkit-qt-1-v0.200.0-aa1c6c414ec021fd32e30492c00bb13347e228db

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	polkit-qt5-1.pc.cmake polkit-qt5-agent-1.pc.cmake
PKGCONFIG_OVERRIDE+=	polkit-qt5-core-1.pc.cmake polkit-qt5-gui-1.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
