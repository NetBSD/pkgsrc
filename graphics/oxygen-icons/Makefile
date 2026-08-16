# $NetBSD: Makefile,v 1.54 2026/08/16 11:44:29 wiz Exp $

DISTNAME=	oxygen-icons-6.29.0
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://invent.kde.org/frameworks/oxygen-icons
COMMENT=	Oxygen icon set for the KDE integrated X11 desktop
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	qt6-qtbase-[0-9]*:../../x11/qt6-qtbase

USE_LANGUAGES=	c c++

# Why a collection of images requires a C++17 compiler is anyone's guess,
# but this is a hard requirement from the KDE cmake infrastructure.
USE_CXX_FEATURES+=	c++17

CMAKE_CONFIGURE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

.include "../../devel/cmake/build.mk"

BUILDLINK_API_DEPENDS.extra-cmake-modules+=	extra-cmake-modules>=6.28.0
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
