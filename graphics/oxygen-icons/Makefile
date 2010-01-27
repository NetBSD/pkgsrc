# $NetBSD: Makefile,v 1.5 2010/01/27 10:38:42 markd Exp $

DISTNAME=	oxygen-icons-4.3.5
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=4.3.5/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	Oxygen icon set for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir

TOOLS_DEPENDS.cmake= cmake>=2.6.3:../../devel/cmake

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_KDE_build

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build

.include "../../mk/bsd.pkg.mk"
