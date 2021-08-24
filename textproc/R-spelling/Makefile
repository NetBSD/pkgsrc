# $NetBSD: Makefile,v 1.2 2021/08/24 11:14:59 mef Exp $

R_PKGNAME=	spelling
R_PKGVER=	2.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for Spell Checking in R
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-knitr>=1.23:../../print/R-knitr
DEPENDS+=	R-commonmark>=1.7:../../textproc/R-commonmark
DEPENDS+=	R-xml2>=1.2.2nb1:../../textproc/R-xml2
DEPENDS+=	R-hunspell-[0-9]*:../../textproc/R-hunspell

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
