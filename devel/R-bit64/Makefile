# $NetBSD: Makefile,v 1.7 2024/10/19 12:04:55 mef Exp $

R_PKGNAME=	bit64
R_PKGVER=	4.5.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	S3 class for vectors of 64-bit integers
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-bit>=4.0.0:../../devel/R-bit

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
