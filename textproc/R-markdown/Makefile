# $NetBSD: Makefile,v 1.10 2025/01/02 21:28:05 mef Exp $

R_PKGNAME=	markdown
R_PKGVER=	1.13
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Render Markdown with the C Library 'Sundown'
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-commonmark-[0-9]*:../../textproc/R-commonmark
DEPENDS+=	R-mime>=0.3:../../mail/R-mime
DEPENDS+=	R-xfun-[0-9]*:../../devel/R-xfun

TEST_DEPENDS+=	R-RCurl-[0-9]*:../../www/R-RCurl
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
