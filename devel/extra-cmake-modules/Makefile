# $NetBSD: Makefile,v 1.4 2016/04/26 09:20:41 markd Exp $

DISTNAME=	extra-cmake-modules-5.21.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/5.21/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Extra modules and scripts for CMake
LICENSE=	modified-bsd

#BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2:../../textproc/py-sphinx

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_KDE_build

CMAKE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_ARGS+=	-DBUILD_HTML_DOCS=OFF
CMAKE_ARGS+=	-DBUILD_MAN_DOCS=OFF

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build

#.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
