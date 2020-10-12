# $NetBSD: Makefile,v 1.7 2020/10/12 21:52:01 bacon Exp $

R_PKGNAME=	RandomFields
R_PKGVER=	3.3.8

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simulation and analysis of random fields
PKGREVISION=	1
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-sp>=1.3.1:../../math/R-sp
DEPENDS+=	R-RandomFieldsUtils>=0.5.1:../../math/R-RandomFieldsUtils

# Packages suggested but not available:
#   'tkrplot', 'spam', 'soma', 'optimx', 'pso', 'GenSA'
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-mvtnorm-[0-9]*:../../math/R-mvtnorm
TEST_DEPENDS+=	R-tcltk2-[0-9]*:../../devel/R-tcltk2

USE_LANGUAGES+=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../math/R-RandomFieldsUtils/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
