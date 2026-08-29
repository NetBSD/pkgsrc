# $NetBSD: Makefile,v 1.40 2026/08/29 21:39:07 mef Exp $

R_PKGNAME=	stringi
R_PKGVER=	1.8.9
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Character string processing facilities
LICENSE=	modified-bsd	# + file LICENSE

TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

# !pdfTeX error: pdflatex (file cm-super-ts1.enc): cannot open encoding file for

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	p5-TeXLive-TLUtils-[0-9]*:../../print/p5-TeXLive-TLUtils
TEST_DEPENDS+=	p5-TeXLive-TLConfig-[0-9]*:../../print/p5-TeXLive-TLConfig

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
