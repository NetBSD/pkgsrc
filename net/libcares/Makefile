# $NetBSD: Makefile,v 1.52 2024/12/24 15:43:03 adam Exp $

DISTNAME=	c-ares-1.34.4
PKGNAME=	${DISTNAME:S/c-/libc/1}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=c-ares/}
GITHUB_PROJECT=	c-ares
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c-ares.org/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

CMAKE_CONFIGURE_ARGS+=	-DCARES_STATIC=ON

PKGCONFIG_OVERRIDE+=	libcares.pc.cmake
PKGCONFIG_OVERRIDE+=	libcares.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
