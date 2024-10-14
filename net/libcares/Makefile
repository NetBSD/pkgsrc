# $NetBSD: Makefile,v 1.49 2024/10/14 22:06:30 wiz Exp $

# NOTE: when updating this, also update the version in
# patches/patch-include_ares__version.h!
DISTNAME=	c-ares-1.34.1
PKGNAME=	${DISTNAME:S/c-/libc/1}
PKGREVISION=	1
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
