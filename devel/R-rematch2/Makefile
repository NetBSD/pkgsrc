# $NetBSD: Makefile,v 1.1 2020/09/19 23:14:21 mef Exp $

R_PKGNAME=	rematch2
R_PKGVER=	2.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tidy Output from Regular Expression Matching
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
