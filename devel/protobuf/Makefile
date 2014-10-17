# $NetBSD: Makefile,v 1.8 2014/10/17 22:00:40 joerg Exp $
#

.include "Makefile.common"

PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://protobuf.googlecode.com/files/

MAINTAINER=	aran@100acres.us
HOMEPAGE=	http://code.google.com/p/protobuf/
COMMENT=	Google protocol buffers
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++ c

SET_LIBDIR=	yes

PKGCONFIG_OVERRIDE+=	protobuf-lite.pc.in
PKGCONFIG_OVERRIDE+=	protobuf.pc.in

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
