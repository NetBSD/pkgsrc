# $NetBSD: Makefile,v 1.1 2021/01/20 11:37:22 nia Exp $

DISTNAME=	libdivsufsort-2.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=y-256/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/y-256/libdivsufsort
COMMENT=	Lightweight suffix array construction algorithm library
LICENSE=	mit

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	pkgconfig/libdivsufsort.pc.cmake

.include "../../mk/bsd.pkg.mk"
