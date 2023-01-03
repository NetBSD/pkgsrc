# $NetBSD: Makefile,v 1.7 2023/01/03 10:14:53 mef Exp $

R_PKGNAME=	purrr
R_PKGVER=	1.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Functional programming tools
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rlang>=0.3.1:../../devel/R-rlang
DEPENDS+=	R-vctrs-[0-9]*:../../math/R-vctrs
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle

TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-tidyselect-[0-9]*:../../devel/R-tidyselect
TEST_DEPENDS+=	R-lubridate-[0-9]*:../../time/R-lubridate

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/R-cli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
