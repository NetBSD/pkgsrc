# $NetBSD: Makefile,v 1.7 2019/08/08 19:53:57 brook Exp $

R_PKGNAME=	stringr
R_PKGVER=	1.4.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple, consistent wrappers for common string operations
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-glue>=1.2.0:../../devel/R-glue
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-stringi>=1.1.7:../../textproc/R-stringi

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
