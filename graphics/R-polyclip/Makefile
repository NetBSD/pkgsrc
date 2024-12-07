# $NetBSD: Makefile,v 1.3 2024/12/07 05:05:10 mef Exp $

R_PKGNAME=	polyclip
R_PKGVER=	1.10-7
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/polyclip/
COMMENT=	Polygon Clipping
LICENSE=	boost-license

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
