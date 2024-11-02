# $NetBSD: Makefile,v 1.1 2024/11/02 02:07:46 mef Exp $

R_PKGNAME=	CompQuadForm
R_PKGVER=	1.4.3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Distribution Function of Quadratic Forms in Normal Variables
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	c++17

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
