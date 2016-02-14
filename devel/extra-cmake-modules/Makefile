# $NetBSD: Makefile,v 1.3 2016/02/14 04:13:32 markd Exp $

DISTNAME=	extra-cmake-modules-5.19.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/5.19/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://projects.kde.org/projects/kdesupport/extra-cmake-modules
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
