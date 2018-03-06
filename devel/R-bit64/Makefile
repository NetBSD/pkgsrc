# $NetBSD: Makefile,v 1.1 2018/03/06 17:07:52 minskim Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ff.r-forge.r-project.org/
COMMENT=	S3 class for vectors of 64-bit integers
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-bit>=1.1.12:../../devel/R-bit

R_PKGNAME=	bit64
R_PKGVER=	0.9-7

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.0.1
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
