# $NetBSD: Makefile,v 1.6 2025/01/04 13:49:52 mef Exp $

R_PKGNAME=	TTR
R_PKGVER=	0.24.4
CATEGORIES=	finance

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Technical trading rules
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo
DEPENDS+=	R-curl>=4.0:../../www/R-curl

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
TEST_DEPENDS+=	R-quantmod-[0-9]*:../../finance/R-quantmod

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../math/R-xts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
