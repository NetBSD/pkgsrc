# $NetBSD: Makefile,v 1.13 2022/04/23 06:44:29 mef Exp $

R_PKGNAME=	rlang
R_PKGVER=	1.0.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Functions for base types and core R and 'Tidyverse' features
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	R-pak-[0-9]*:../../devel/R-pak
TEST_DEPENDS+=	R-pillar-[0-9]*:../../misc/R-pillar
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-vctrs-[0-9]*:../../math/R-vctrs

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
