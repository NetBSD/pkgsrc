# $NetBSD: Makefile,v 1.3 2020/07/31 20:44:49 brook Exp $

R_PKGNAME=	dplyr
R_PKGVER=	1.0.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Grammar of data manipulation
LICENSE=	mit

DEPENDS+=	R-BH>=1.69.0.1:../../devel/R-BH
DEPENDS+=	R-R6>=2.4.0:../../devel/R-R6
DEPENDS+=	R-assertthat>=0.2.0:../../devel/R-assertthat
DEPENDS+=	R-glue>=1.3.2:../../devel/R-glue
DEPENDS+=	R-lifecycle>=0.2.0:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=0.4.6:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=1.1.0:../../devel/R-tidyselect
DEPENDS+=	R-ellipsis>=0.3.0:../../math/R-ellipsis
DEPENDS+=	R-generics>=0.0.2:../../math/R-generics
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-vctrs>=0.3.0:../../math/R-vctrs

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/R-plogr/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
