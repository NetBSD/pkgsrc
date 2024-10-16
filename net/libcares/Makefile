# $NetBSD: Makefile,v 1.50 2024/10/16 08:51:31 adam Exp $

DISTNAME=	c-ares-1.34.2
PKGNAME=	${DISTNAME:S/c-/libc/1}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=c-ares/}
GITHUB_PROJECT=	c-ares
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c-ares.haxx.se/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

CMAKE_CONFIGURE_ARGS+=	-DCARES_STATIC=ON

PKGCONFIG_OVERRIDE+=	libcares.pc.cmake
PKGCONFIG_OVERRIDE+=	libcares.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
