# $NetBSD: Makefile,v 1.25 2025/02/08 04:23:34 taca Exp $

DISTNAME=	msgpack-c-6.1.0
PKGNAME=	${DISTNAME:S/-c-/-/}
PKGREVISION=	2
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
.include "../../textproc/cJSON/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
