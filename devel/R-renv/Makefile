# $NetBSD: Makefile,v 1.5 2024/10/19 22:57:12 mef Exp $

R_PKGNAME=	renv
R_PKGVER=	1.0.11
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Project Environments
LICENSE=	mit	# + file LICENSE

USE_LANGUAGES=	# none
REPLACE_SH=	inst/bin/renv inst/resources/scripts-git-askpass.sh

# Packages suggested but not available:
#   'BiocManager', 'jsonvalidate', 'modules', 'packrat', 'reticulate',

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-devtools-[0-9]*:../../devel/R-devtools
TEST_DEPENDS+=	R-pak-[0-9]*:../../devel/R-pak
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-miniUI-[0-9]*:../../www/R-miniUI
TEST_DEPENDS+=	R-webfakes-[0-9]*:../../www/R-webfakes


.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
