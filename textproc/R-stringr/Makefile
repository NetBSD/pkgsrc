# $NetBSD: Makefile,v 1.6 2019/07/31 20:58:08 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/stringr/
COMMENT=	Simple, consistent wrappers for common string operations
LICENSE=	gnu-gpl-v2

R_PKGNAME=	stringr
R_PKGVER=	1.4.0

DEPENDS+=	R-glue>=1.2.0:../../devel/R-glue
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-stringi>=1.1.7:../../textproc/R-stringi

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
