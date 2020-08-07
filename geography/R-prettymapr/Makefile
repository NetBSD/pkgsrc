# $NetBSD: Makefile,v 1.1 2020/08/07 03:19:21 brook Exp $

R_PKGNAME=	prettymapr
R_PKGVER=	0.2.2
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Scale Bar, North Arrow, and Pretty Margins in R
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-plyr>=1.8.6:../../math/R-plyr
DEPENDS+=	R-digest>=0.6.25:../../security/R-digest
DEPENDS+=	R-rjson>=0.2.20:../../textproc/R-rjson
DEPENDS+=	R-httr>=1.4.1:../../www/R-httr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
