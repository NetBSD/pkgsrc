# $NetBSD: Makefile,v 1.3 2026/05/22 13:39:31 mef Exp $

R_PKGNAME=	fastmatch
R_PKGVER=	1.1-8

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast 'match()' Function
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
