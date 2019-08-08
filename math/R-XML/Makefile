# $NetBSD: Makefile,v 1.11 2019/08/08 19:53:46 brook Exp $

R_PKGNAME=	XML
R_PKGVER=	3.98-1.20
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for parsing and generating XML within R
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
