# $NetBSD: Makefile,v 1.4 2018/02/05 18:58:56 minskim Exp $

CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/stringr/
COMMENT=	Make it easier to work with strings
LICENSE=	gnu-gpl-v2

R_PKGNAME=	stringr
R_PKGVER=	1.2.0

DEPENDS=	R-stringi>=0.4.1:../../textproc/R-stringi \
		R-magrittr>=0:../../devel/R-magrittr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
