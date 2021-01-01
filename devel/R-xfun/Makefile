# $NetBSD: Makefile,v 1.5 2021/01/01 11:58:53 mef Exp $

R_PKGNAME=	xfun
R_PKGVER=	0.19
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Miscellaneous functions by 'Yihui Xie'
LICENSE=	mit

# Packages suggested but not available:
#  'testit', 'pak'
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-tinytex-[0-9]*:../../print/R-tinytex
TEST_DEPENDS+=	R-testit-[0-9]*:../../devel/R-testit
TEST_DEPENDS+=	R-pak-[0-9]*:../../devel/R-pak

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
