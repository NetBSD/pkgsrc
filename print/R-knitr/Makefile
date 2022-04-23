# $NetBSD: Makefile,v 1.14 2022/04/23 14:31:10 mef Exp $

R_PKGNAME=	knitr
R_PKGVER=	1.38
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	General-purpose package for dynamic report generation in R
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-evaluate>=0.15:../../devel/R-evaluate
DEPENDS+=	R-xfun>=0.29:../../devel/R-xfun
DEPENDS+=	R-digest>=0.6.4:../../security/R-digest
DEPENDS+=	R-formatR>=0.10:../../textproc/R-formatR
DEPENDS+=	R-highr>=0.8:../../textproc/R-highr
DEPENDS+=	R-markdown>=1.0:../../textproc/R-markdown
DEPENDS+=	R-stringr>=0.6:../../textproc/R-stringr
DEPENDS+=	R-yaml>=2.1.19:../../textproc/R-yaml

TEST_DEPENDS+=	R-highr-[0-9]*:../../textproc/R-highr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-testit-[0-9]*:../../devel/R-testit
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-rgl-[0-9]*:../../graphics/R-rgl
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2
TEST_DEPENDS+=	R-webshot-[0-9]*:../../www/R-webshot
TEST_DEPENDS+=	R-DBI-[0-9]*:../../math/R-DBI
TEST_DEPENDS+=	R-png-[0-9]*:../../graphics/R-png
TEST_DEPENDS+=	R-jpeg-[0-9]*:../../graphics/R-jpeg
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
#EST_DEPENDS+=	R-ragg-[0-9]*:../../graphics/R-ragg

# Packages suggested but not available:
#  'tikzDevice', 'reticulate', 'JuliaCall', 'magick', 'gifski',
#  'showtext', 'ragg', 'styler', 'targets'

USE_LANGUAGES=	# none

REPLACE_RSCRIPT+=	inst/bin/knit
REPLACE_RSCRIPT+=	inst/examples/knit-all.R

REPLACE_INTERPRETER+=	Rscript
REPLACE.Rscript.old=	.*Rscript
REPLACE.Rscript.new=	${PREFIX}/bin/Rscript
REPLACE_FILES.Rscript=	${REPLACE_RSCRIPT}

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
