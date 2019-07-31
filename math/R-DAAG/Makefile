# $NetBSD: Makefile,v 1.14 2019/07/31 18:05:13 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/DAAG/
COMMENT=	Data analysis and graphics data and functions
LICENSE=	gnu-gpl-v3

R_PKGNAME=	DAAG
R_PKGVER=	1.22.1

DEPENDS+=	R-latticeExtra>=0.6.26:../../graphics/R-latticeExtra

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
