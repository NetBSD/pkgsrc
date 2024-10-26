# $NetBSD: Makefile,v 1.9 2024/10/26 22:01:48 mef Exp $

R_PKGNAME=	VGAM
R_PKGVER=	1.1-12

MAINTAINER=	mishka@NetBSD.org
COMMENT=	Vector generalized linear and additive models
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c fortran

# Package suggested but not available: 'VGAMextra'
# Package which this enhances but not available for checking: 'VGAMdata'
TEST_DEPENDS+=	R-VGAMdata-[0-9]*:../../math/R-VGAMdata
TEST_DEPENDS+=	R-VGAMextra-[0-9]*:../../math/R-VGAMextra

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec


.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
