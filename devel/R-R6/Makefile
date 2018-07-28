# $NetBSD: Makefile,v 1.2 2018/07/28 14:40:42 brook Exp $

CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/wch/R6/
COMMENT=	Classes with reference semantics
LICENSE=	mit

R_PKGNAME=	R6
R_PKGVER=	2.2.2

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
