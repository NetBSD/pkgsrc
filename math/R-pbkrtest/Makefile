# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:52 brook Exp $

R_PKGNAME=	pbkrtest
R_PKGVER=	0.4-7
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parametric bootstrap and Kenward Roger based methods for mixed model comparison
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-lme4>=1.1.10:../../math/R-lme4

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
