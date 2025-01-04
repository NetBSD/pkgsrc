# $NetBSD: Makefile,v 1.8 2025/01/04 01:08:36 mef Exp $

R_PKGNAME=	yaml
R_PKGVER=	2.3.10
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Methods to convert R data to YAML and back
LICENSE=	modified-bsd

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
