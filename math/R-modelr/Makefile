# $NetBSD: Makefile,v 1.1 2022/04/23 05:15:16 mef Exp $

R_PKGNAME=	modelr
R_PKGVER=	0.1.8

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modelling Functions that Work with the Pipe
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-purrr>=0.2.2:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.2.0:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=1.1.1:../../devel/R-tidyselect
DEPENDS+=	R-broom>=0.7.9:../../math/R-broom
DEPENDS+=	R-tibble>=3.1.4:../../math/R-tibble
DEPENDS+=	R-tidyr>=0.8.0:../../math/R-tidyr
DEPENDS+=	R-vctrs>=0.3.8:../../math/R-vctrs

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
