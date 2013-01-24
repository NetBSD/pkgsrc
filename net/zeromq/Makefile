# $NetBSD: Makefile,v 1.9 2013/01/24 11:28:03 obache Exp $
#

DISTNAME=	zeromq-2.2.0
CATEGORIES=	net devel
MASTER_SITES=	http://download.zeromq.org/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.zeromq.org/
COMMENT=	The ZeroMQ messaging library
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	src/libzmq.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
