# $NetBSD: Makefile,v 1.5 2022/12/31 12:24:57 mef Exp $

R_PKGNAME=	tinytex
R_PKGVER=	0.43
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Helper Func. to Install & Maintain 'TeX Live' & Compile 'LaTeX' Docs
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-xfun>=0.23:../../devel/R-xfun

TEST_DEPENDS+=	R-testit-[0-9]*:../../devel/R-testit
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
