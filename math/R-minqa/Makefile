# $NetBSD: Makefile,v 1.6 2024/02/03 11:04:04 mef Exp $

R_PKGNAME=	minqa
R_PKGVER=	1.2.6

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Derivative-free optimization algorithms by quadratic approximation
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
