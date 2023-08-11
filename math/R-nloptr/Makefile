# $NetBSD: Makefile,v 1.9 2023/08/11 08:41:09 mef Exp $

R_PKGNAME=	nloptr
R_PKGVER=	2.0.3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R interface to NLopt
LICENSE=	gnu-lgpl-v3

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-inline-[0-9]*:../../devel/R-inline
#EST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c c++ fortran77
USE_TOOLS+=	pkg-config

.include "../../math/R/Makefile.extension"
.include "../../math/nlopt/buildlink3.mk"
.include "../../devel/R-testthat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
