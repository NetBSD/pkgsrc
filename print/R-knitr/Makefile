# $NetBSD: Makefile,v 1.1 2014/09/20 04:03:40 brook Exp $

CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/knitr/
COMMENT=	A general-purpose package for dynamic report generation in R
# TODO: LICENSE=	GPL

R_PKGNAME=	knitr
R_PKGVER=	1.6

DEPENDS+=	R-evaluate>=0.5.3:../../devel/R-evaluate
DEPENDS+=	R-digest>=0.6.4:../../security/R-digest
DEPENDS+=	R-formatR>=0.10:../../textproc/R-formatR
DEPENDS+=	R-highr>=0.3:../../textproc/R-highr
DEPENDS+=	R-markdown>=0.6.5:../../textproc/R-markdown
DEPENDS+=	R-stringr>=0.6:../../textproc/R-stringr

REPLACE_RSCRIPT+=	inst/bin/knit
REPLACE_RSCRIPT+=	inst/examples/knit-all.R

REPLACE_INTERPRETER+=	Rscript
REPLACE.Rscript.old=	.*Rscript
REPLACE.Rscript.new=	${PREFIX}/bin/Rscript
REPLACE_FILES.Rscript=	${REPLACE_RSCRIPT}

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
