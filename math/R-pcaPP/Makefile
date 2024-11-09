# $NetBSD: Makefile,v 1.2 2024/11/09 14:30:04 mef Exp $

R_PKGNAME=	pcaPP
R_PKGVER=	2.0-5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Robust PCA by Projection Pursuit
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-mvtnorm>=1.2.5:../../math/R-mvtnorm
DEPENDS+=	R-robustbase-[0-9]*:../../math/R-robustbase

# !pdfTeX error: pdflatex (file ecti1200): Font ecti1200 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
