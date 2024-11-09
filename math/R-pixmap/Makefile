# $NetBSD: Makefile,v 1.12 2024/11/09 22:13:42 mef Exp $

R_PKGNAME=	pixmap
R_PKGVER=	0.4-13

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Functions for manipulations of bitmaps with R
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
