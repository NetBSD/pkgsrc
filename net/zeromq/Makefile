# $NetBSD: Makefile,v 1.24 2017/02/02 10:09:53 fhajny Exp $

DISTNAME=	zeromq-4.2.1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeromq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zeromq.org/
COMMENT=	The ZeroMQ messaging library
LICENSE=	gnu-lgpl-v3

GITHUB_PROJECT=	libzmq
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libsodium=${BUILDLINK_PREFIX.libsodium}

PKGCONFIG_OVERRIDE+=	src/libzmq.pc.in

TEST_TARGET=	check

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-*)
CXXFLAGS+=	-std=gnu++0x
.endif

.if !empty(CC_VERSION:Mclang-*)
CXXFLAGS+=	-std=gnu++11
.endif

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
