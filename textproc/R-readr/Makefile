# $NetBSD: Makefile,v 1.7 2023/06/17 14:14:38 mef Exp $

R_PKGNAME=	readr
R_PKGVER=	2.1.4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read rectangular text data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-BH>=1.69.0.1:../../devel/R-BH
DEPENDS+=	R-R6>=2.4.0:../../devel/R-R6
DEPENDS+=	R-clipr>=0.7.0:../../devel/R-clipr
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-hms>=0.4.1:../../time/R-hms
DEPENDS+=	R-vroom-[0-9]*:../../textproc/R-vroom

TEST_DEPENDS+=	R-clipr-[0-9]*:../../devel/R-clipr
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-vroom-[0-9]*:../../textproc/R-vroom
TEST_DEPENDS+=	R-waldo-[0-9]*:../../devel/R-waldo

TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
post-install:
	install_name_tool \
		-change \
		@loader_path/../rcon/librcon.so \
		${PREFIX}/lib/R/library/readr/rcon/librcon.so \
		${DESTDIR}${PREFIX}/lib/R/library/readr/libs/readr.so
.endif

.include "../../math/R/Makefile.extension"

# Can't find librcon.so during test.
R_PKG_INSTALL_ARGS+=	--no-test-load

.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../time/R-tzdb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
