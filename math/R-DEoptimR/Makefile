# $NetBSD: Makefile,v 1.7 2024/01/23 15:31:18 mef Exp $

R_PKGNAME=	DEoptimR
R_PKGVER=	1.1-3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Differential evolution optimization in pure R
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3


TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
