# $NetBSD: Makefile,v 1.10 2021/05/31 22:04:13 mef Exp $

R_PKGNAME=	cli
R_PKGVER=	2.5.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Helpers for developing command line interfaces
LICENSE=	mit

DEPENDS+=	R-assertthat>=0.2.1:../../devel/R-assertthat
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-fansi-[0-9]*:../../devel/R-fansi
DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue

TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-prettycode-[0-9]*:../../devel/R-prettycode
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES=	# none

REPLACE_RSCRIPT+=	inst/examples/apps/*.R
REPLACE_RSCRIPT+=	inst/scripts/*.R

REPLACE_INTERPRETER+=	Rscript
REPLACE.Rscript.old=	.*Rscript
REPLACE.Rscript.new=	${PREFIX}/bin/Rscript
REPLACE_FILES.Rscript=	${REPLACE_RSCRIPT}

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
