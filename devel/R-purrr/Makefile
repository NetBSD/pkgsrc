# $NetBSD: Makefile,v 1.2 2020/07/31 18:22:34 brook Exp $

R_PKGNAME=	purrr
R_PKGVER=	0.3.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Functional programming tools
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rlang>=0.3.1:../../devel/R-rlang

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
