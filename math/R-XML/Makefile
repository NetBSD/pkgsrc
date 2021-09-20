# $NetBSD: Makefile,v 1.17 2021/09/20 00:01:07 mef Exp $

R_PKGNAME=	XML
R_PKGVER=	3.99-0.8

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for parsing and generating XML within R
LICENSE=	2-clause-bsd

DEPENDS+=	R-bitops-[0-9]*:../../math/R-bitops
DEPENDS+=	R-RCurl-[0-9]*:../../www/R-RCurl

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
