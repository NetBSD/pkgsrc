# $NetBSD: Makefile,v 1.56 2026/07/07 05:48:04 wiz Exp $

DISTNAME=		c-ares-1.34.7
PKGNAME=		${DISTNAME:S/c-/libc/1}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=c-ares/}
GITHUB_PROJECT=		c-ares
#GITHUB_RELEASE=	v${PKGVERSION_NOREV}
# post 1.34.7 on 1.34 branch, fixing an API breakage
GITHUB_TAG=		636f85326908a521f232c7e7acb6c3484582391d

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c-ares.org/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

CMAKE_CONFIGURE_ARGS+=	-DCARES_STATIC=ON

PKGCONFIG_OVERRIDE+=	libcares.pc.cmake
PKGCONFIG_OVERRIDE+=	libcares.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
