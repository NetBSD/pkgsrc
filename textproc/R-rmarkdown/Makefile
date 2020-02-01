# $NetBSD: Makefile,v 1.2 2020/02/01 02:24:03 mef Exp $

R_PKGNAME=	rmarkdown
R_PKGVER=	2.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Dynamic Documents for R
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-base64enc>=0.1.3:../../converters/R-base64enc
DEPENDS+=	R-evaluate>=0.13:../../devel/R-evaluate
DEPENDS+=	R-xfun>=0.8:../../devel/R-xfun
DEPENDS+=	R-mime>=0.7:../../mail/R-mime
DEPENDS+=	R-knitr>=1.22:../../print/R-knitr
DEPENDS+=	R-htmltools>=0.3.5:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-stringr>=1.2.0:../../textproc/R-stringr
DEPENDS+=	R-yaml>=2.1.19:../../textproc/R-yaml
DEPENDS+=	R-tinytex-[0-9]*:../../print/R-tinytex

# Packages suggested but not available: 'tufte', 'dygraphs', 'pkgdown'
TEST_DEPENDS+=	R-base64enc-[0-9]*:../../converters/R-base64enc
TEST_DEPENDS+=	R-fs-[0-9]*:../../devel/R-fs

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
