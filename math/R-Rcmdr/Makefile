# $NetBSD: Makefile,v 1.4 2008/10/14 07:25:31 markd Exp $
#

CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		${R_HOMEPAGE_BASE}/Rcmdr/
COMMENT=		Platform-independent basic-statistics GUI for R

R_PKGNAME=		Rcmdr
R_PKGVER=		1.4-2

DEPENDS+=		tcl>=8.3:../../lang/tcl

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
