# $NetBSD: Makefile,v 1.5 2024/01/23 13:33:38 mef Exp $

R_PKGNAME=	rio
R_PKGVER=	1.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Swiss-army knife for data I/O
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-data.table>=1.11.2:../../textproc/R-data.table
DEPENDS+=	R-haven>=1.1.2:../../textproc/R-haven
DEPENDS+=	R-openxlsx>=4.1.0.1:../../textproc/R-openxlsx
DEPENDS+=	R-readxl>=0.1.1:../../textproc/R-readxl
DEPENDS+=	R-curl>=0.6:../../www/R-curl

# Packages suggested but not available:
#   'arrow', 'fst', 'hexView', 'pzfx', 'readODS', 'rmatio'

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
#TEST_DEPENDS+=	R-arrow-[0-9]*
TEST_DEPENDS+=	R-feather-[0-9]*:../../devel/R-feather
#TEST_DEPENDS+=	R-fst-[0-9]*
#TEST_DEPENDS+=	R-hexView-[0-9]*
#TEST_DEPENDS+=	R-pzfx-[0-9]*
#TEST_DEPENDS+=	R-readODS-[0-9]*
#TEST_DEPENDS+=	R-rmatio-[0-9]*


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
../../devel/R-R.utils
