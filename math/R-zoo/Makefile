# $NetBSD: Makefile,v 1.12 2018/07/28 14:40:51 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/zoo/
COMMENT=	S3 Infrastructure for Regular and Irregular Time Series
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	zoo
R_PKGVER=	1.8-1

BUILDLINK_API_DEPENDS.R+=	R>=2.10.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
