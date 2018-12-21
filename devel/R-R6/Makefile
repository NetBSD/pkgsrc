# $NetBSD: Makefile,v 1.3 2018/12/21 06:25:09 wen Exp $

CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/wch/R6/
COMMENT=	Classes with reference semantics
LICENSE=	mit

R_PKGNAME=	R6
R_PKGVER=	2.3.0

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=3.0
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
