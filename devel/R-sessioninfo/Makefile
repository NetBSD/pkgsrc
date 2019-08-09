# $NetBSD: Makefile,v 1.1 2019/08/09 18:34:34 brook Exp $

R_PKGNAME=	sessioninfo
R_PKGVER=	1.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R session information
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
