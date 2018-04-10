# $NetBSD: Makefile,v 1.5 2018/04/10 01:02:24 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://r-dbi.github.io/DBI
COMMENT=	R Database Interface
LICENSE=	gnu-lgpl-v2

R_PKGNAME=	DBI
R_PKGVER=	0.8

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.0.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
