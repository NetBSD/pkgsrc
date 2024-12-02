# $NetBSD: Makefile,v 1.1 2024/12/02 12:25:47 mef Exp $

R_PKGNAME=	spatstat.univar
R_PKGVER=	3.1-1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	One-Dimensional Probability Distribution Support for the 'spatstat' Family
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.utils>=3.1.1:../../geography/R-spatstat.utils

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
