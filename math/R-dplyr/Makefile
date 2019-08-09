# $NetBSD: Makefile,v 1.1 2019/08/09 16:23:47 brook Exp $

R_PKGNAME=	dplyr
R_PKGVER=	0.8.3
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Grammar of data manipulation
LICENSE=	mit

DEPENDS+=	R-assertthat>=0.2.0:../../devel/R-assertthat
DEPENDS+=	R-glue>=1.3.0:../../devel/R-glue
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=0.2.5:../../devel/R-tidyselect
DEPENDS+=	R-tibble>=2.0.0:../../math/R-tibble

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/R-plogr/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
