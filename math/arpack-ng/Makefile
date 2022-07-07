# $NetBSD: Makefile,v 1.7 2022/07/07 13:39:48 thor Exp $

DISTNAME=	arpack-ng-3.8.0
PKGREVISION=	2
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

.include "../../mk/blas.buildlink3.mk"
CMAKE_ARGS+=	-DBLA_PREFER_PKGCONFIG=true -DBLA_PKGCONFIG_BLAS=${BLAS_PC}

.include "options.mk"

TEST_TARGET=	test

pre-configure:
	cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

INSTALLATION_DIRS=	lib

.include "../../mk/bsd.pkg.mk"
