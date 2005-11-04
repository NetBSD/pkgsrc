# $NetBSD: Makefile,v 1.1.1.1 2005/11/04 08:10:09 rillig Exp $
#

CATEGORIES=             math
MASTER_SITES=           ${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=             mchittur@cs.nmsu.edu
HOMEPAGE=               ${R_HOMEPAGE_BASE}/Rcmdr.html
COMMENT=		Platform-independent basic-statistics GUI for R

R_PKGNAME=              Rcmdr
R_PKGVER=               0.9-11

DEPENDS+=		tcl>=8.3:../../lang/tcl

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
