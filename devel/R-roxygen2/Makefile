# $NetBSD: Makefile,v 1.1 2019/08/09 19:12:14 brook Exp $

R_PKGNAME=	roxygen2
R_PKGVER=	6.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	In-line documentation for R
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-pkgload>=1.0.2:../../devel/R-pkgload
DEPENDS+=	R-purrr>=0.3.2:../../devel/R-purrr
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-brew>=1.0.6:../../textproc/R-brew
DEPENDS+=	R-commonmark>=1.7:../../textproc/R-commonmark
DEPENDS+=	R-stringi>=1.4.3:../../textproc/R-stringi
DEPENDS+=	R-stringr>=1.0.0:../../textproc/R-stringr
DEPENDS+=	R-xml2>=1.2.2:../../textproc/R-xml2

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
