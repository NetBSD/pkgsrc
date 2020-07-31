# $NetBSD: Makefile,v 1.3 2020/07/31 20:17:39 brook Exp $

R_PKGNAME=	vctrs
R_PKGVER=	0.3.2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Vector helpers
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-glue>=1.4.1:../../devel/R-glue
DEPENDS+=	R-rlang>=0.4.7:../../devel/R-rlang
DEPENDS+=	R-backports>=1.1.4:../../math/R-backports
DEPENDS+=	R-ellipsis>=0.2.0:../../math/R-ellipsis
DEPENDS+=	R-zeallot>=0.1.0:../../math/R-zeallot
DEPENDS+=	R-digest>=0.6.25:../../security/R-digest

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
