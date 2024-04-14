# $NetBSD: Makefile,v 1.45 2024/04/14 08:15:58 wiz Exp $

DISTNAME=	c-ares-1.28.1
PKGNAME=	${DISTNAME:S/c-/libc/1}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://c-ares.haxx.se/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c-ares.haxx.se/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

CMAKE_ARGS+=	-DCARES_STATIC=ON

PKGCONFIG_OVERRIDE+=	libcares.pc.cmake
PKGCONFIG_OVERRIDE+=	libcares.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
