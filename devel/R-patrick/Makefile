# $NetBSD: Makefile,v 1.1 2022/12/18 02:33:53 mef Exp $

R_PKGNAME=	patrick
R_PKGVER=	0.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parameterized Unit Testing
LICENSE=	apache-2.0

DEPENDS+=	R-purrr>=0.3.4:../../devel/R-purrr
DEPENDS+=	R-rlang>=1.0.6:../../devel/R-rlang
DEPENDS+=	R-testthat>=3.1.5:../../devel/R-testthat
DEPENDS+=	R-dplyr>=1.0.9:../../math/R-dplyr
DEPENDS+=	R-tibble>=3.1.4:../../math/R-tibble

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
