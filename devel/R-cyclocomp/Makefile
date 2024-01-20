# $NetBSD: Makefile,v 1.2 2024/01/20 05:48:54 mef Exp $

R_PKGNAME=	cyclocomp
R_PKGVER=	1.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cyclomatic Complexity of R Code
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-callr>=3.4.1:../../devel/R-callr
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-remotes>=2.1.0:../../devel/R-remotes
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
