# $NetBSD: Makefile,v 1.16 2021/08/22 01:43:42 mef Exp $

R_PKGNAME=	XML
R_PKGVER=	3.99-0.7

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for parsing and generating XML within R
LICENSE=	2-clause-bsd

DEPENDS+=	R-bitops-[0-9]*:../../math/R-bitops
DEPENDS+=	R-RCurl-[0-9]*:../../www/R-RCurl

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
