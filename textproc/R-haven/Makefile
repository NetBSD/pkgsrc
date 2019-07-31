# $NetBSD: Makefile,v 1.1 2019/07/31 13:45:24 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/haven/
COMMENT=	Import and export 'SPSS', 'Stata' and 'SAS' files
LICENSE=	mit

R_PKGNAME=	haven
R_PKGVER=	2.1.1

DEPENDS+=	R-forcats>=0.2.0:../../math/R-forcats
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-readr>=0.1.0:../../textproc/R-readr
DEPENDS+=	R-hms>=0.5.0:../../time/R-hms

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
