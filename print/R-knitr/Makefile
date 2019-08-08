# $NetBSD: Makefile,v 1.8 2019/08/08 19:53:55 brook Exp $

R_PKGNAME=	knitr
R_PKGVER=	1.23
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	General-purpose package for dynamic report generation in R
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-evaluate>=0.10:../../devel/R-evaluate
DEPENDS+=	R-xfun>=0.8:../../devel/R-xfun
DEPENDS+=	R-digest>=0.6.4:../../security/R-digest
DEPENDS+=	R-formatR>=0.10:../../textproc/R-formatR
DEPENDS+=	R-highr>=0.8:../../textproc/R-highr
DEPENDS+=	R-markdown>=1.0:../../textproc/R-markdown
DEPENDS+=	R-stringr>=0.6:../../textproc/R-stringr
DEPENDS+=	R-yaml>=2.1.19:../../textproc/R-yaml

USE_LANGUAGES=	# none

REPLACE_RSCRIPT+=	inst/bin/knit
REPLACE_RSCRIPT+=	inst/examples/knit-all.R

REPLACE_INTERPRETER+=	Rscript
REPLACE.Rscript.old=	.*Rscript
REPLACE.Rscript.new=	${PREFIX}/bin/Rscript
REPLACE_FILES.Rscript=	${REPLACE_RSCRIPT}

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
