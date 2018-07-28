# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:42 brook Exp $

CATEGORIES=	devel

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
