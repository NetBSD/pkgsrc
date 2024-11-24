# $NetBSD: Makefile,v 1.16 2024/11/24 08:13:01 mef Exp $

R_PKGNAME=	xts
R_PKGVER=	0.14.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	eXtensible Time Series
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-zoo>=1.7.12:../../math/R-zoo

TEST_DEPENDS+=	R-chron-[0-9]*:../../math/R-chron
TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
TEST_DEPENDS+=	R-timeDate-[0-9]*:../../time/R-timeDate
TEST_DEPENDS+=	R-timeSeries-[0-9]*:../../finance/R-timeSeries
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-tseries-[0-9]*:../../finance/R-tseries

# !pdfTeX error: pdflatex (file ecti1000): Font ecti1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
