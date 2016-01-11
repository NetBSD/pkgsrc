# $NetBSD: Makefile,v 1.2 2016/01/11 00:02:32 markd Exp $

DISTNAME=	extra-cmake-modules-5.18.0
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/5.18/}
EXTRACT_SUFX=	.tar.xz
EXTRACT_USING=	bsdtar

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://projects.kde.org/projects/kdesupport/extra-cmake-modules
COMMENT=	Extra modules and scripts for CMake
LICENSE=	gnu-lgpl-v3

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
