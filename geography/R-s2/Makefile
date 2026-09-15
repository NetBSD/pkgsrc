# $NetBSD: Makefile,v 1.14 2026/09/15 10:06:22 wiz Exp $

R_PKGNAME=	s2
R_PKGVER=	1.1.7
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spherical Geometry Operators Using the S2 Geometry Library
LICENSE=	apache-2.0

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-vctrs-[0-9]*:../../math/R-vctrs

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=		c c++
# somehow, -std=gnu++20 ends up on the compiler command line,
# but the code is not ready for that (e.g. std::allocator::rebind
# was removed in C++20); so force C++17
FORCE_CXX_STD=		gnu++17
USE_CXX_FEATURES=	c++20

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/R-wk/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
