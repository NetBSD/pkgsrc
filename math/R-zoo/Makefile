# $NetBSD: Makefile,v 1.13 2018/08/30 12:19:26 wen Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/zoo/
COMMENT=	S3 Infrastructure for Regular and Irregular Time Series
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	zoo
R_PKGVER=	1.8-3

BUILDLINK_API_DEPENDS.R+=	R>=3.1.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
