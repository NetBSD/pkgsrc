# $NetBSD: Makefile,v 1.4 2019/01/27 14:59:18 wen Exp $

CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rlang.tidyverse.org/
COMMENT=	Functions for base types, core R and Tidyverse features
LICENSE=	gnu-gpl-v3

R_PKGNAME=	rlang
R_PKGVER=	0.3.1

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.1.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
