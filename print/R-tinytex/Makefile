# $NetBSD: Makefile,v 1.7 2024/12/14 10:45:43 mef Exp $

R_PKGNAME=	tinytex
R_PKGVER=	0.54
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Helper Func. to Install & Maintain 'TeX Live' & Compile 'LaTeX' Docs
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-xfun>=0.23:../../devel/R-xfun

TEST_DEPENDS+=	R-testit-[0-9]*:../../devel/R-testit
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
