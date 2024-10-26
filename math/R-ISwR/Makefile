# $NetBSD: Makefile,v 1.13 2024/10/26 06:36:16 mef Exp $

R_PKGNAME=	ISwR
R_PKGVER=	2.0-9
CATEGORIES=	math databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Data sets and scripts for 'Introductory Statistics with R'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
