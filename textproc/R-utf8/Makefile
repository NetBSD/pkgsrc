# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:52 brook Exp $

CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/patperry/r-utf8
COMMENT=	Unicode text processing
LICENSE=	apache-2.0

R_PKGNAME=	utf8
R_PKGVER=	1.1.3

USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.R+=	R>=3.1.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
