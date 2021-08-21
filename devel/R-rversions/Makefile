# $NetBSD: Makefile,v 1.3 2021/08/21 05:47:19 mef Exp $

R_PKGNAME=	rversions
R_PKGVER=	2.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Query 'R' Versions, Including 'r-release' and 'r-oldrel'
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2
DEPENDS+=	R-curl-[0-9]*:../../www/R-curl

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
