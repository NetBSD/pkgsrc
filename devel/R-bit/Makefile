# $NetBSD: Makefile,v 1.3 2018/07/28 14:40:42 brook Exp $

CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ff.r-forge.r-project.org/
COMMENT=	Class for vectors of 1-bit booleans
LICENSE=	gnu-gpl-v2

R_PKGNAME=	bit
R_PKGVER=	1.1-14

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=2.9.2
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
