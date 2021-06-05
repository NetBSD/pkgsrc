# $NetBSD: Makefile,v 1.8 2021/06/05 07:32:59 mef Exp $

R_PKGNAME=	stringr
R_PKGVER=	1.4.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple, consistent wrappers for common string operations
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-glue>=1.2.0:../../devel/R-glue
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-stringi>=1.1.7:../../textproc/R-stringi

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
