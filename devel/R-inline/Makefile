# $NetBSD: Makefile,v 1.7 2025/01/12 12:54:52 mef Exp $

R_PKGNAME=	inline
R_PKGVER=	0.3.21
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Functions to inline C, C++, Fortran function calls from R
LICENSE=	gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

# see buildlink3.mk inclusion
#EST_DEPENDS+=	R-Rcpp-[0-9]*:../../devel/R-Rcpp
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++ fortran

# this line is required for make test
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
