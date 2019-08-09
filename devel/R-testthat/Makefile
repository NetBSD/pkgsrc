# $NetBSD: Makefile,v 1.1 2019/08/09 18:39:07 brook Exp $

R_PKGNAME=	testthat
R_PKGVER=	2.2.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Unit testing for R
LICENSE=	mit

DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-evaluate>=0.14:../../devel/R-evaluate
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
DEPENDS+=	R-withr>=2.0.0:../../devel/R-withr
DEPENDS+=	R-praise>=1.0.0:../../misc/R-praise
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
