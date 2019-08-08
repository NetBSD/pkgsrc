# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:56 brook Exp $

R_PKGNAME=	progress
R_PKGVER=	1.2.2
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Terminal progress bars
LICENSE=	mit

DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits
DEPENDS+=	R-hms>=0.5.0:../../time/R-hms

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
