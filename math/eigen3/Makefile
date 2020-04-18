# $NetBSD: Makefile,v 1.13 2020/04/18 22:01:56 joerg Exp $

DISTNAME=	3.3.7
PKGNAME=	eigen3-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://bitbucket.org/eigen/eigen/get/
DIST_SUBDIR=	eigen3
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eigen.tuxfamily.org/
COMMENT=	C++ template library for linear algebra
LICENSE=	mpl-2.0

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build
WRKSRC=		${WRKDIR}/eigen-eigen-323c052e1731

CMAKE_ARGS+=	-DCMAKEPACKAGE_INSTALL_DIR=${PREFIX}/lib/cmake/eigen3
CMAKE_ARGS+=	-DPKGCONFIG_INSTALL_DIR=${PREFIX}/lib/pkgconfig

PKGCONFIG_OVERRIDE+=	eigen3.pc.in

pre-configure:
	${MKDIR} ${WRKSRC}/_build

.include "../../mk/bsd.pkg.mk"
