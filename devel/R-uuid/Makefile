# $NetBSD: Makefile,v 1.9 2024/10/26 05:03:45 mef Exp $

R_PKGNAME=	uuid
R_PKGVER=	1.2-1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for generating and handling of UUIDs
LICENSE=	mit

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
