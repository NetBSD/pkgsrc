# $NetBSD: Makefile,v 1.2 2022/03/14 11:18:03 mef Exp $

R_PKGNAME=	unix
R_PKGVER=	1.5.4
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	POSIX System Utilities
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
