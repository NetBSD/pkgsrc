# $NetBSD: Makefile,v 1.2 2018/06/01 02:08:10 wen Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rlang.tidyverse.org/
COMMENT=	Functions for base types, core R and Tidyverse features
LICENSE=	gnu-gpl-v3

R_PKGNAME=	rlang
R_PKGVER=	0.2.1

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.1.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
