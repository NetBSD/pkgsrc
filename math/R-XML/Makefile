# $NetBSD: Makefile,v 1.15 2021/04/21 11:42:09 adam Exp $

R_PKGNAME=	XML
R_PKGVER=	3.99-0.5
PKGREVISION=	1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for parsing and generating XML within R
LICENSE=	2-clause-bsd

DEPENDS+=	R-bitops-[0-9]*:../../math/R-bitops
DEPENDS+=	R-RCurl-[0-9]*:../../www/R-RCurl

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
