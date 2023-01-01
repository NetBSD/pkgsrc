# $NetBSD: Makefile,v 1.5 2023/01/01 00:51:37 mef Exp $

R_PKGNAME=	purrr
R_PKGVER=	1.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Functional programming tools
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rlang>=0.3.1:../../devel/R-rlang

# Package suggested but not available: 'lubridate'
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-tidyselect-[0-9]*:../../devel/R-tidyselect

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/R-cli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
