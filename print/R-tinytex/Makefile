# $NetBSD: Makefile,v 1.6 2023/02/18 10:53:56 mef Exp $

R_PKGNAME=	tinytex
R_PKGVER=	0.44
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
