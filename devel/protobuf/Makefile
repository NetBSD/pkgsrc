# $NetBSD: Makefile,v 1.3 2012/10/31 11:19:26 asau Exp $
#

DISTNAME=	protobuf-2.4.1
CATEGORIES=	devel
MASTER_SITES=	http://protobuf.googlecode.com/files/

MAINTAINER=	aran@100acres.us
HOMEPAGE=	http://code.google.com/p/protobuf/
COMMENT=	Google protocol buffers
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++ c

PKGCONFIG_OVERRIDE+=	protobuf-lite.pc.in
PKGCONFIG_OVERRIDE+=	protobuf.pc.in

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
