# $NetBSD: Makefile,v 1.1 2019/07/31 13:40:18 brook Exp $

CATEGORIES=	sysutils R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/progress/
COMMENT=	Terminal progress bars
LICENSE=	mit

R_PKGNAME=	progress
R_PKGVER=	1.2.2

DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits
DEPENDS+=	R-hms>=0.5.0:../../time/R-hms

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
