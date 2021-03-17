# $NetBSD: Makefile,v 1.14 2021/03/17 17:20:00 prlw1 Exp $

DISTNAME=	eigen-3.3.9
PKGNAME=	${DISTNAME:S/eigen/eigen3/}
CATEGORIES=	math
MASTER_SITES=	https://gitlab.com/libeigen/eigen/-/archive/3.3.9/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eigen.tuxfamily.org/
COMMENT=	C++ template library for linear algebra
LICENSE=	mpl-2.0

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

CMAKE_ARGS+=	-DCMAKEPACKAGE_INSTALL_DIR=lib/cmake/eigen3
CMAKE_ARGS+=	-DPKGCONFIG_INSTALL_DIR=lib/pkgconfig

PKGCONFIG_OVERRIDE+=	eigen3.pc.in

pre-configure:
	${MKDIR} ${WRKSRC}/_build

.include "../../mk/bsd.pkg.mk"
