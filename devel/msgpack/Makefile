# $NetBSD: Makefile,v 1.23 2024/08/19 11:51:48 adam Exp $

DISTNAME=	msgpack-c-6.1.0
PKGNAME=	${DISTNAME:S/-c-/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msgpack/}
GITHUB_PROJECT=	msgpack-c
GITHUB_RELEASE=	c-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	boost-license

USE_LANGUAGES=		c
PKGCONFIG_OVERRIDE=	msgpack.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
