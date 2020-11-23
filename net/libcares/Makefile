# $NetBSD: Makefile,v 1.29 2020/11/23 15:47:19 wiz Exp $

DISTNAME=	c-ares-1.17.1
PKGNAME=	${DISTNAME:S/c-/libc/1}
CATEGORIES=	net
MASTER_SITES=	https://c-ares.haxx.se/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c-ares.haxx.se/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

USE_CMAKE=	yes
CMAKE_ARGS+=	-DCARES_STATIC=ON

.include "../../mk/bsd.pkg.mk"
