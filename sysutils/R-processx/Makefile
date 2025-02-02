# $NetBSD: Makefile,v 1.12 2025/02/02 22:40:32 mef Exp $

R_PKGNAME=	processx
R_PKGVER=	3.8.5
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Execute and control system processes
LICENSE=	mit

DEPENDS+=	R-R6>=2.4.0:../../devel/R-R6
DEPENDS+=	R-ps>=1.2.0:../../sysutils/R-ps

# Package suggested but not available: 'debugme'
TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-debugme-[0-9]*:../../devel/R-debugme
TEST_DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-webfakes-[0-9]*:../../www/R-webfakes
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

LIBS.SunOS+=	-lsocket -lnsl

.include "../../math/R/Makefile.extension"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
