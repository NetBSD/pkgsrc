# $NetBSD: Makefile,v 1.1 2020/08/09 15:19:41 brook Exp $

R_PKGNAME=	osmdata
R_PKGVER=	0.1.3
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Import 'OpenStreetMap' Data as Simple Features or Spatial Objects
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-sp>=1.3.1:../../math/R-sp
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-xml2>=1.2.2nb1:../../textproc/R-xml2
DEPENDS+=	R-lubridate>=1.7.4:../../time/R-lubridate
DEPENDS+=	R-curl>=4.2:../../www/R-curl
DEPENDS+=	R-httr>=1.4.1:../../www/R-httr
DEPENDS+=	R-rvest>=0.3.5:../../www/R-rvest

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
