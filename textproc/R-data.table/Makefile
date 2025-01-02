# $NetBSD: Makefile,v 1.7 2025/01/02 10:06:55 mef Exp $

R_PKGNAME=	data.table
R_PKGVER=	1.16.4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension of 'data.frame'
LICENSE=	mpl-2.0

# Packages suggested but not available:
#  'nanotime'

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-bit-[0-9]*:../../devel/R-bit
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-R.utils-[0-9]*:../../devel/R-R.utils
TEST_DEPENDS+=	R-nanotime-[0-9]*:../../time/R-nanotime
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-xts-[0-9]*:../../math/R-xts
TEST_DEPENDS+=	R-yaml-[0-9]*:../../textproc/R-yaml
TEST_DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
