# $NetBSD: Makefile,v 1.2 2025/01/12 11:18:00 mef Exp $

R_PKGNAME=	popbio
R_PKGVER=	2.8
CATEGORIES=	biology

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Construction and Analysis of Matrix Population Models
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	R-quadprog-[0-9]*:../../math/R-quadprog

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
