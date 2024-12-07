# $NetBSD: Makefile,v 1.5 2024/12/07 03:04:37 mef Exp $

R_PKGNAME=	labeling
R_PKGVER=	0.4.3
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Axis labeling
LICENSE=	mit

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
