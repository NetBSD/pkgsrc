# $NetBSD: Makefile,v 1.2 2019/09/07 13:16:27 maya Exp $

R_PKGNAME=	promises
R_PKGVER=	1.0.1
CATEGORIES=	parallel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Abstractions for promise-based asynchronous programming
LICENSE=	mit

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../sysutils/R-later/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
