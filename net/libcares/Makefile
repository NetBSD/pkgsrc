# $NetBSD: Makefile,v 1.36 2023/11/06 13:54:49 wiz Exp $

DISTNAME=	c-ares-1.21.0
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
