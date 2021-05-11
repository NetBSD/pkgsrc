# $NetBSD: Makefile,v 1.5 2021/05/11 10:18:37 prlw1 Exp $

DISTNAME=	arpack-ng-3.8.0
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

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
