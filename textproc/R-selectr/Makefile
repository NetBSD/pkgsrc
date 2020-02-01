# $NetBSD: Makefile,v 1.2 2020/02/01 04:50:30 mef Exp $

R_PKGNAME=	selectr
R_PKGVER=	0.4-2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Translate CSS Selectors to XPath Expressions
LICENSE=	modified-bsd

DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6

# make test do not pass yet
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
