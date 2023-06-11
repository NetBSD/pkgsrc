# $NetBSD: Makefile,v 1.4 2023/06/11 23:00:18 mef Exp $

R_PKGNAME=	forcats
R_PKGVER=	1.0.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for working with categorical variables (factors)
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-ellipsis>=0.2.0.1:../../math/R-ellipsis
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
