# $NetBSD: Makefile,v 1.10 2024/01/23 14:18:42 mef Exp $

R_PKGNAME=	BH
R_PKGVER=	1.84.0-0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Boost C++ header files
LICENSE=	boost-license

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
