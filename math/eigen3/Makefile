# $NetBSD: Makefile,v 1.6 2015/11/15 12:06:33 prlw1 Exp $

DISTNAME=	3.2.7
PKGNAME=	eigen3-3.2.7
CATEGORIES=	math
MASTER_SITES=   http://bitbucket.org/eigen/eigen/get/
DIST_SUBDIR=	eigen3
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eigen.tuxfamily.org/
COMMENT=	C++ template library for linear algebra
LICENSE=	mpl-2.0

USE_LANGUAGES+= c c++
USE_CMAKE= yes
CMAKE_ARG_PATH= ..
CONFIGURE_DIRS= _build
WRKSRC=		${WRKDIR}/eigen-eigen-b30b87236a1b

pre-configure:
	${MKDIR} ${WRKSRC}/_build

.include "../../mk/bsd.pkg.mk"
