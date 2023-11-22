# $NetBSD: Makefile,v 1.38 2023/11/22 11:48:32 adam Exp $

DISTNAME=	c-ares-1.22.1
PKGNAME=	${DISTNAME:S/c-/libc/1}
CATEGORIES=	net
MASTER_SITES=	https://c-ares.haxx.se/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c-ares.haxx.se/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

CMAKE_ARGS+=	-DCARES_STATIC=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
