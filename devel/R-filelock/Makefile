# $NetBSD: Makefile,v 1.2 2024/01/20 07:42:27 mef Exp $

R_PKGNAME=	filelock
R_PKGVER=	1.0.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Portable File Locking
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
