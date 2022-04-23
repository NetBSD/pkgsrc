# $NetBSD: Makefile,v 1.2 2022/04/23 04:53:59 mef Exp $

R_PKGNAME=	tidyverse
R_PKGVER=	1.3.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily Install and Load the 'Tidyverse'
LICENSE=	mit	# + file LICENSE

BROKEN=		'dtplyr, googledrive, googlesheets4, modelr, reprex are not available'


DEPENDS+=	R-dbplyr>=2.1.1:../../databases/R-dbplyr
DEPENDS+=	R-cli>=2.4.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.4.1:../../devel/R-crayon
DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-purrr>=0.3.4:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.4.10:../../devel/R-rlang
DEPENDS+=	R-ggplot2>=3.3.3:../../graphics/R-ggplot2
DEPENDS+=	R-broom>=0.7.6:../../math/R-broom
DEPENDS+=	R-dplyr>=1.0.5:../../math/R-dplyr
DEPENDS+=	R-forcats>=0.5.1:../../math/R-forcats
DEPENDS+=	R-rstudioapi>=0.13:../../math/R-rstudioapi
DEPENDS+=	R-tibble>=3.1.0:../../math/R-tibble
DEPENDS+=	R-tidyr>=1.1.3:../../math/R-tidyr
DEPENDS+=	R-pillar>=1.6.0:../../misc/R-pillar
DEPENDS+=	R-haven>=2.3.1:../../textproc/R-haven
DEPENDS+=	R-jsonlite>=1.7.2:../../textproc/R-jsonlite
DEPENDS+=	R-readr>=1.4.0:../../textproc/R-readr
DEPENDS+=	R-readxl>=1.3.1:../../textproc/R-readxl
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr
DEPENDS+=	R-xml2>=1.3.2nb1:../../textproc/R-xml2
DEPENDS+=	R-hms>=1.0.0:../../time/R-hms
DEPENDS+=	R-lubridate>=1.7.10:../../time/R-lubridate
DEPENDS+=	R-httr>=1.4.2:../../www/R-httr
DEPENDS+=	R-rvest>=1.0.0:../../www/R-rvest

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
