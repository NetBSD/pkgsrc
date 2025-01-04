# $NetBSD: Makefile,v 1.5 2025/01/04 22:28:30 mef Exp $

R_PKGNAME=	fBasics
R_PKGVER=	4041.97
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Markets and basic statistics
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-timeSeries>=3042.102:../../finance/R-timeSeries
DEPENDS+=	R-gss>=2.1.7:../../math/R-gss
DEPENDS+=	R-stabledist>=0.7.1:../../math/R-stabledist
DEPENDS+=	R-timeDate>=3042.101:../../time/R-timeDate

TEST_DEPENDS+=	R-interp-[0-9]*:../../graphics/R-interp
TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
