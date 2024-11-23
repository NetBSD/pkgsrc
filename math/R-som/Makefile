# $NetBSD: Makefile,v 1.2 2024/11/23 22:40:04 mef Exp $

R_PKGNAME=	som
R_PKGVER=	0.3-5.2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Self-Organizing Map
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
