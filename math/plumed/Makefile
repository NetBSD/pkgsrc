# $NetBSD: Makefile,v 1.2 2022/07/25 14:57:58 thor Exp $

DISTNAME=	plumed-2.8.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=plumed/plumed2/releases/download/v2.8.0/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	thor@NetBSD.org
HOMEPAGE=	https://www.plumed.org/
COMMENT=	Molecular dynamics support library
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++ fortran
USE_TOOLS+=	gmake bash

TEST_TARGET=	check

CONFIGURE_ARGS+=	--enable-gsl
CONFIGURE_ARGS+=	--enable-external-blas --enable-external-lapack
CONFIGURE_ARGS+=	LIBS='${LAPACK_LIBS} ${CBLAS_LIBS}'
CONFIGURE_ARGS+=	LIBRARY_PATH='${LIBRARY_PATH}:${PREFIX}/lib'
CONFIGURE_ARGS+=	--enable-rpath
# Python module should be a separate package, I suppose.
# it is a versioned .so file, so differing pythons might coexist.
CONFIGURE_ARGS+=	--disable-python

SUBST_CLASSES+=		envbash
SUBST_STAGE.envbash=	pre-configure
SUBST_FILES.envbash=	src/lib/Makefile
SUBST_SED.envbash=	-e 's,/usr/bin/env bash,${BASH},'

REPLACE_BASH+=	scripts/*.sh patches/*.sh

.include "options.mk"

BLAS_C_INTERFACE=	yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
