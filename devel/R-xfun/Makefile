# $NetBSD: Makefile,v 1.4 2020/10/03 13:59:16 mef Exp $

R_PKGNAME=	xfun
R_PKGVER=	0.18
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Miscellaneous functions by 'Yihui Xie'
LICENSE=	mit

# Packages suggested but not available:
#  'testit', 'pak'
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-tinytex-[0-9]*:../../print/R-tinytex

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
