# $NetBSD: Makefile,v 1.1 2021/05/29 09:55:14 thor Exp $

DISTNAME=	qrupdate-1.1.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qrupdate/}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://qrupdate.sourceforge.io/
COMMENT=	Library for fast updating of QR and Cholesky decompositions
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	fortran
USE_TOOLS=	gmake
REPLACE_SH=	test/report_results

TEST_TARGET=	test

MAKE_FLAGS=	FC=${FC:Q} LDFLAGS=${LDFLAGS:Q} FFLAGS=${FFLAGS:Q} PREFIX=${PREFIX} LIBDIR=lib
MAKE_FLAGS+=	BLAS=${BLAS_LIBS} LAPACK=${LAPACK_LIBS}

do-build:
	cd ${WRKSRC} && gmake ${MAKE_FLAGS} FPICFLAGS= lib \
	&& rm src/*.o && gmake ${MAKE_FLAGS} FPICFLAGS=-fPIC solib

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
