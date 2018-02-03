# $NetBSD: Makefile,v 1.1 2018/02/03 01:48:14 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/quantprog/
COMMENT=	Functions to solve quadratic programming problems
LICENSE=	gnu-gpl-v2

R_PKGNAME=	quadprog
R_PKGVER=	1.5-5

USE_LANGUAGES=	c fortran

BUILDLINK_API_DEPENDS.R+=	R>=2.15.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
