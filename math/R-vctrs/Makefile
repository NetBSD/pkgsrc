# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:54 brook Exp $

R_PKGNAME=	vctrs
R_PKGVER=	0.2.0
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Vector helpers
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-glue>=1.3.1:../../devel/R-glue
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-backports>=1.1.4:../../math/R-backports
DEPENDS+=	R-ellipsis>=0.2.0:../../math/R-ellipsis
DEPENDS+=	R-zeallot>=0.1.0:../../math/R-zeallot
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
