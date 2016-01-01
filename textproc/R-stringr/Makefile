# $NetBSD: Makefile,v 1.2 2016/01/01 13:38:34 wen Exp $

CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/stringr/
COMMENT=	Make it easier to work with strings
LICENSE=	gnu-gpl-v2

R_PKGNAME=	stringr
R_PKGVER=	1.0.0

DEPENDS=	R-stringi>=0.4.1:../../textproc/R-stringi \
		R-magrittr>=0:../../devel/R-magrittr

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
