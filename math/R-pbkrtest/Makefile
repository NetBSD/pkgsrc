# $NetBSD: Makefile,v 1.3 2019/07/31 20:09:59 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/pbkrtest/
COMMENT=	Parametric bootstrap and Kenward Roger based methods for mixed model comparison
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	pbkrtest
R_PKGVER=	0.4-7

DEPENDS+=	R-lme4>=1.1.10:../../math/R-lme4

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
