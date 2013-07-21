# $NetBSD: Makefile,v 1.11 2013/07/21 12:01:55 obache Exp $

DISTNAME=	zeromq-3.2.3
CATEGORIES=	net devel
MASTER_SITES=	http://download.zeromq.org/

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

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
