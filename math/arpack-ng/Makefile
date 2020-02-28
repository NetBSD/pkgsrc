# $NetBSD: Makefile,v 1.1 2020/02/28 21:51:40 plunky Exp $

DISTNAME=	arpack-ng-3.7.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=opencollab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opencollab/arpack-ng
COMMENT=	Library of subroutines to solve eigenvalue problems
LICENSE=	original-bsd

USE_LANGUAGES=	c fortran
USE_CMAKE=	yes

OBJDIR=		obj

CONFIGURE_DIRS=	${OBJDIR}

CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON

TEST_TARGET=	test

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

INSTALLATION_DIRS=	lib

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
