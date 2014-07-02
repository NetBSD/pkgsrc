# $NetBSD: Makefile,v 1.15 2014/07/02 08:00:04 mbalmer Exp $

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

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Mgcc)
CXXFLAGS+=	-std=gnu++0x
.endif

.include "../../security/libsodium/buildlink3.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
