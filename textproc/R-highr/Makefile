# $NetBSD: Makefile,v 1.10 2025/01/02 11:56:16 mef Exp $

R_PKGNAME=	highr
R_PKGVER=	0.11
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntax highlighting for R source code
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-xfun-[0-9]*:../../devel/R-xfun

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-testit-[0-9]*:../../devel/R-testit

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
