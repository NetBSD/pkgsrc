# $NetBSD: Makefile,v 1.3 2020/09/20 21:32:33 mef Exp $

R_PKGNAME=	purrr
R_PKGVER=	0.3.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Functional programming tools
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rlang>=0.3.1:../../devel/R-rlang

TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-tidyselect-[0-9]*:../../devel/R-tidyselect

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
