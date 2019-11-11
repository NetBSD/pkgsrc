# $NetBSD: Makefile,v 1.14 2019/11/11 06:38:05 markd Exp $

DISTNAME=	extra-cmake-modules-5.64.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Extra modules and scripts for CMake
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_KDE_build

CMAKE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_ARGS+=	-DBUILD_HTML_DOCS=OFF
CMAKE_ARGS+=	-DBUILD_MAN_DOCS=OFF
CMAKE_ARGS+=	-DBUILD_QTHELP_DOCS=OFF

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build
	${FIND} ${WRKSRC} -name \*.orig -exec rm {} \;

.include "../../mk/bsd.pkg.mk"
