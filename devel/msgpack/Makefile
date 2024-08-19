# $NetBSD: Makefile,v 1.24 2024/08/19 12:06:07 wiz Exp $

DISTNAME=	msgpack-c-6.1.0
PKGNAME=	${DISTNAME:S/-c-/-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msgpack/}
GITHUB_PROJECT=	msgpack-c
GITHUB_RELEASE=	c-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	boost-license

USE_LANGUAGES=		c
PKGCONFIG_OVERRIDE=	msgpack-c.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
