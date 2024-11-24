# $NetBSD: Makefile,v 1.3 2024/11/24 05:35:00 mef Exp $

R_PKGNAME=	tensorA
R_PKGVER=	0.36.2.1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Advanced tensor arithmetic with named indices
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
