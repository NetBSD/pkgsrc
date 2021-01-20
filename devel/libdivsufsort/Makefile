# $NetBSD: Makefile,v 1.2 2021/01/20 11:39:32 nia Exp $

DISTNAME=	libdivsufsort-2.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=y-256/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/y-256/libdivsufsort
COMMENT=	Lightweight suffix array construction algorithm library
LICENSE=	mit

USE_CMAKE=	yes

# Examples do not get installed.
CMAKE_ARGS+=	-DBUILD_EXAMPLES=OFF

PKGCONFIG_OVERRIDE+=	pkgconfig/libdivsufsort.pc.cmake

.include "../../mk/bsd.pkg.mk"
