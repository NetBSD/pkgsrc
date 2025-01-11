# $NetBSD: Makefile,v 1.3 2025/01/11 12:22:26 mef Exp $

R_PKGNAME=	getPass
R_PKGVER=	0.2-4
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Masked User Input
LICENSE=	2-clause-bsd  # and See LICENSE

DEPENDS+=	R-rstudioapi>=0.5:../../math/R-rstudioapi

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
TEST_DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
TEST_DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
TEST_DEPENDS+=	tex-parskip-[0-9]*:../../print/tex-parskip
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
