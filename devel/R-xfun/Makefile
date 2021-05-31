# $NetBSD: Makefile,v 1.8 2021/05/31 23:48:13 mef Exp $

R_PKGNAME=	xfun
R_PKGVER=	0.23
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Miscellaneous functions by 'Yihui Xie'
LICENSE=	mit

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-tinytex>=0.31:../../print/R-tinytex
TEST_DEPENDS+=	R-testit-[0-9]*:../../devel/R-testit
TEST_DEPENDS+=	R-pa-[0-9]*:../../devel/R-pakk
#EST_DEPENDS+=	R-renv-[0-9]*:../../devel/R-renv

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
