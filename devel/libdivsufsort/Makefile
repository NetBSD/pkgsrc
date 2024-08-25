# $NetBSD: Makefile,v 1.3 2024/08/25 06:18:35 wiz Exp $

DISTNAME=	libdivsufsort-2.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=y-256/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/y-256/libdivsufsort
COMMENT=	Lightweight suffix array construction algorithm library
LICENSE=	mit

USE_CMAKE=	yes

# Examples do not get installed.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXAMPLES=OFF

PKGCONFIG_OVERRIDE+=	pkgconfig/libdivsufsort.pc.cmake

.include "../../mk/bsd.pkg.mk"
