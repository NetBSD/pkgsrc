# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:50 brook Exp $
#

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/pbkrtest/
COMMENT=	Parametric bootstrap and Kenward-Roger-based methods
LICENSE=	gnu-gpl-v2

R_PKGNAME=	pbkrtest
R_PKGVER=	0.4-7

USE_LANGUAGES=	# none

DEPENDS+=	R-lme4>=1.1.10:../../math/R-lme4

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
