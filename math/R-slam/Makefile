# $NetBSD: Makefile,v 1.2 2024/11/23 13:27:34 mef Exp $

R_PKGNAME=	slam
R_PKGVER=	0.1-55

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Sparse Lightweight Arrays and Matrices
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
