# $NetBSD: Makefile,v 1.1 2018/03/13 17:02:17 minskim Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/r-lib/cli
COMMENT=	Helpers for developing command line interfaces
LICENSE=	mit

R_PKGNAME=	cli
R_PKGVER=	1.0.0

DEPENDS+=	R-assertthat-[0-9]*:../../devel/R-assertthat
DEPENDS+=	R-crayon-[0-9]*:../../devel/R-crayon

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.10
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
