# $NetBSD: Makefile,v 1.32 2023/10/24 22:10:56 wiz Exp $

DISTNAME=	polkit-qt-1-0.114.0
PKGNAME=	${DISTNAME:S/-qt-1-/-qt5-/}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://invent.kde.org/libraries/polkit-qt-1/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invent.kde.org/libraries/polkit-qt-1
COMMENT=	Qt5 Wrapper around PolicyKit
LICENSE=	gnu-lgpl-v2.1

WRKSRC=         ${WRKDIR}/polkit-qt-1-v0.114.0-ccab85232550419100207ed61fe1bbbb35c112ff

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	polkit-qt5-1.pc.cmake polkit-qt5-agent-1.pc.cmake
PKGCONFIG_OVERRIDE+=	polkit-qt5-core-1.pc.cmake polkit-qt5-gui-1.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
