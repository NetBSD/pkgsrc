# $NetBSD: Makefile,v 1.1 2019/08/09 16:25:23 brook Exp $

R_PKGNAME=	tidyr
R_PKGVER=	0.8.3
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily tidy data with 'spread()' and 'gather()' functions
LICENSE=	mit

DEPENDS+=	R-glue>=1.3.1:../../devel/R-glue
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-purrr>=0.3.2:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=0.2.5:../../devel/R-tidyselect
DEPENDS+=	R-dplyr>=0.7.0:../../math/R-dplyr
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-stringi>=1.4.3:../../textproc/R-stringi

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
