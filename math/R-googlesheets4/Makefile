# $NetBSD: Makefile,v 1.1 2022/04/23 14:21:53 mef Exp $

R_PKGNAME=	googlesheets4
R_PKGVER=	1.0.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Access Google Sheets using the Sheets API V4
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-cli>=3.0.0:../../devel/R-cli
DEPENDS+=	R-glue>=1.3.0:../../devel/R-glue
DEPENDS+=	R-googledrive-[0-9]*:../../www/R-googledrive
DEPENDS+=	R-ids-[0-9]*:../../math/R-ids
DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-purrr>=0.3.4:../../devel/R-purrr
DEPENDS+=	R-rematch2>=2.1.2:../../devel/R-rematch2
DEPENDS+=	R-rlang>=0.4.11:../../devel/R-rlang
DEPENDS+=	R-tibble>=2.1.1:../../math/R-tibble
DEPENDS+=	R-vctrs>=0.2.3:../../math/R-vctrs
DEPENDS+=	R-cellranger>=1.1.0:../../textproc/R-cellranger
DEPENDS+=	R-curl>=4.3.2nb2:../../www/R-curl
DEPENDS+=	R-httr>=1.4.2:../../www/R-httr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
