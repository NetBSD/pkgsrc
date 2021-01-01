# $NetBSD: Makefile,v 1.10 2021/01/01 03:24:52 mef Exp $

R_PKGNAME=	rlang
R_PKGVER=	0.4.9
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Functions for base types and core R and 'Tidyverse' features
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
#EST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
