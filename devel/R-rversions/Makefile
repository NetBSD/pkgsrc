# $NetBSD: Makefile,v 1.4 2022/12/18 04:56:30 mef Exp $

R_PKGNAME=	rversions
R_PKGVER=	2.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Query 'R' Versions, Including 'r-release' and 'r-oldrel'
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2
DEPENDS+=	R-curl-[0-9]*:../../www/R-curl

TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
