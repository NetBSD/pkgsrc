# $NetBSD: Makefile,v 1.12 2026/07/05 13:26:16 mef Exp $

R_PKGNAME=	RcppArmadillo
R_PKGVER=	15.2.6-1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Rcpp integration for the Armadillo templated linear algebra library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available: 'reticulate'
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-pkgKitten-[0-9]*:../../devel/R-pkgKitten
TEST_DEPENDS+=	R-slam-[0-9]*:../../math/R-slam

USE_LANGUAGES=		c++ fortran
USE_CXX_FEATURES+=	c++11
# configure claims 7.5 is too old
GCC_REQD+=		8

.include "../../mk/bsd.prefs.mk"
SUBST_CLASSES+=		pkglibs
SUBST_STAGE.pkglibs=	pre-configure
SUBST_FILES.pkglibs=	src/Makevars.in
SUBST_MESSAGE.pkglibs=	Add -lexecinfo for *BSD
.if ${OPSYS} != SunOS && ${OPSYS} != Linux && ${OPSYS} != Darwin
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,PKG_LIBS+=-lexecinfo,
.else
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,,
.endif

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
