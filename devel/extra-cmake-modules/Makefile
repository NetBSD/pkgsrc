# $NetBSD: Makefile,v 1.8 2018/03/24 20:13:40 joerg Exp $

DISTNAME=	extra-cmake-modules-5.41.0
PKGREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/5.41/}
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
	${FIND} ${WRKSRC} -name \*.orig -exec rm {} \;

#.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
