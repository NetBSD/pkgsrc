# $NetBSD: Makefile,v 1.12 2020/06/02 08:24:15 adam Exp $

R_PKGNAME=	XML
R_PKGVER=	3.98-1.20
PKGREVISION=	1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for parsing and generating XML within R
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
