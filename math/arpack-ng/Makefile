# $NetBSD: Makefile,v 1.6 2021/06/23 18:10:19 thor Exp $

DISTNAME=	arpack-ng-3.8.0
PKGREVISION=	1
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

BLAS_ACCEPTED=	netlib openblas
.include "../../mk/blas.buildlink3.mk"
.if ${BLAS_TYPE} == "netlib"
CMAKE_ARGS+=	-DBLA_VENDOR=Generic
.elif ${BLAS_TYPE} == "openblas"
CMAKE_ARGS+=	-DBLA_VENDOR=OpenBLAS
.endif

TEST_TARGET=	test

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

INSTALLATION_DIRS=	lib

.include "../../mk/bsd.pkg.mk"
