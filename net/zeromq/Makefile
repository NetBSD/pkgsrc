# $NetBSD: Makefile,v 1.18 2014/07/07 13:21:27 joerg Exp $

DISTNAME=	zeromq-4.0.4
CATEGORIES=	net devel
MASTER_SITES=	http://download.zeromq.org/
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zeromq.org/
COMMENT=	The ZeroMQ messaging library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	src/libzmq.pc.in

TEST_TARGET=	check

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-*)
CXXFLAGS+=	-std=gnu++0x
.endif

.if !empty(CC_VERSION:Mclang-*)
CXXFLAGS+=	-std=gnu++11
.endif

.include "../../security/libsodium/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libsodium=${BUILDLINK_PREFIX.libsodium}

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
