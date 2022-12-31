# $NetBSD: Makefile,v 1.2 2022/12/31 10:37:42 mef Exp $

R_PKGNAME=	gitcreds
R_PKGVER=	0.1.2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Query 'git' Credentials from 'R'
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-oskeyring-[0-9]*:../../security/R-oskeyring
USE_LANGUAGES=	# none

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
