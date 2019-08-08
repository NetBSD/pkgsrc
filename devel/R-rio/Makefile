# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:40 brook Exp $

R_PKGNAME=	rio
R_PKGVER=	0.5.16
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Swiss-army knife for data I/O
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-data.table>=1.9.8:../../textproc/R-data.table
DEPENDS+=	R-haven>=1.1.0:../../textproc/R-haven
DEPENDS+=	R-openxlsx>=4.1.0.1:../../textproc/R-openxlsx
DEPENDS+=	R-readxl>=0.1.1:../../textproc/R-readxl
DEPENDS+=	R-curl>=0.6:../../www/R-curl

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
