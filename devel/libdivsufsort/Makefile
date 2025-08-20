# $NetBSD: Makefile,v 1.4 2025/08/20 11:34:51 wiz Exp $

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
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PKGCONFIG_OVERRIDE+=	pkgconfig/libdivsufsort.pc.cmake

.include "../../mk/bsd.pkg.mk"
