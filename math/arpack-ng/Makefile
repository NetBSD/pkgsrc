# $NetBSD: Makefile,v 1.3 2020/11/19 19:58:27 mcf Exp $

DISTNAME=	arpack-ng-3.7.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=opencollab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opencollab/arpack-ng
COMMENT=	Library of subroutines to solve eigenvalue problems
LICENSE=	original-bsd

USE_LANGUAGES=	c fortran
USE_CMAKE=	yes

# Required to build with gfortran 10. Fixed upstream in
# https://github.com/opencollab/arpack-ng/commit/9418632214
FFLAGS+=	-fallow-argument-mismatch

OBJDIR=		obj

CONFIGURE_DIRS=	${OBJDIR}

CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON

TEST_TARGET=	test

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

INSTALLATION_DIRS=	lib

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
