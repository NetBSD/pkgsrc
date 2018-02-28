# $NetBSD: Makefile,v 1.4 2018/02/28 17:45:59 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/DBI/
COMMENT=	R Database Interface
LICENSE=	gnu-lgpl-v2

R_PKGNAME=	DBI
R_PKGVER=	0.7

BUILDLINK_API_DEPENDS.R+=	R>=3.0.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
