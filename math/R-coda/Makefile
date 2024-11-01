# $NetBSD: Makefile,v 1.6 2024/11/01 23:02:56 mef Exp $

R_PKGNAME=	coda
R_PKGVER=	0.19-4.1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Output analysis and diagnostics for MCMC
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES+=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
