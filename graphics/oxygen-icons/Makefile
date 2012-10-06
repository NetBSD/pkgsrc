# $NetBSD: Makefile,v 1.18 2012/10/06 14:11:09 asau Exp $

DISTNAME=	oxygen-icons-4.8.4
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=4.8.4/src/}
EXTRACT_SUFX=	.tar.xz
EXTRACT_USING=	gtar

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	Oxygen icon set for the KDE integrated X11 desktop
LICENSE=	gnu-lgpl-v3

TOOLS_DEPENDS.cmake= cmake>=2.6.3:../../devel/cmake

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_KDE_build

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build

.include "../../mk/bsd.pkg.mk"
