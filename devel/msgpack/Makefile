# $NetBSD: Makefile,v 1.10 2017/08/06 19:19:33 adam Exp $

DISTNAME=	msgpack-2.1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msgpack/}
GITHUB_RELEASE=	cpp-${PKGVERSION_NOREV}
GITHUB_PROJECT=	msgpack-c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	boost-license

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	msgpack.pc.in
TEST_TARGET=		test

.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
