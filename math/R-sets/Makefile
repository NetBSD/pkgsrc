# $NetBSD: Makefile,v 1.3 2024/11/23 13:13:55 mef Exp $

R_PKGNAME=	sets
R_PKGVER=	1.0-25

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sets, Generalized Sets, Customizable Sets and Intervals
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-proxy-[0-9]*:../../math/R-proxy

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TEST_DEPENDS+=	tex-texlive.infra-[0-9]*:../../print/tex-texlive.infra
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
