# $NetBSD: Makefile,v 1.5 2024/01/20 02:58:38 mef Exp $

R_PKGNAME=	sys
R_PKGVER=	3.4.2
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Powerful and reliable tools for running system commands in R
LICENSE=	mit

TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-unix-[0-9]*:../../sysutils/R-unix
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
