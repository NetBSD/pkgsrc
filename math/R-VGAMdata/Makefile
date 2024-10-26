# $NetBSD: Makefile,v 1.1 2024/10/26 12:59:55 mef Exp $

R_PKGNAME=	VGAMdata
R_PKGVER=	1.1-12

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Data Supporting the 'VGAM' Package
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-VGAM>=1.1.12:../../math/R-VGAM

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
