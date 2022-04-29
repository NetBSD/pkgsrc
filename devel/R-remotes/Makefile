# $NetBSD: Makefile,v 1.6 2022/04/29 15:29:46 mef Exp $

R_PKGNAME=	remotes
R_PKGVER=	2.4.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R package installation from remote repositories, including 'GitHub'
LICENSE=	mit

# Package suggested but not available: 'webfakes'
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-brew-[0-9]*:../../textproc/R-brew
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-git2r-[0-9]*:../../devel/R-git2r
TEST_DEPENDS+=	R-pingr-[0-9]*:../../net/R-pingr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-webfakes-[0-9]*:../../www/R-webfakes

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
