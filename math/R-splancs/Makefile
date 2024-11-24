# $NetBSD: Makefile,v 1.11 2024/11/24 01:43:20 mef Exp $

R_PKGNAME=	splancs
R_PKGVER=	2.01-45

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial and space-time point pattern analysis
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-sp>=0.9:../../math/R-sp

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
