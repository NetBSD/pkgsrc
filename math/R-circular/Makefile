# $NetBSD: Makefile,v 1.17 2024/01/24 23:03:32 mef Exp $

R_PKGNAME=	circular
R_PKGVER=	0.5-0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Circular statistics
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-mvtnorm>=1.0.8:../../math/R-mvtnorm

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	fortran c

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
