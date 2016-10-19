# $NetBSD: Makefile,v 1.11 2016/10/19 12:13:00 wiz Exp $

.include "Makefile.common"

DISTNAME=	protobuf-cpp-${PROTOBUFVER}
PKGNAME=	${DISTNAME:S/-cpp//}

MAINTAINER=	aran@100acres.us
COMMENT=	Google protocol buffers

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++ c
USE_TOOLS+=	autoreconf automake autoconf

SET_LIBDIR=	yes

PKGCONFIG_OVERRIDE+=	protobuf-lite.pc.in
PKGCONFIG_OVERRIDE+=	protobuf.pc.in

TEST_TARGET=	check

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh


.include "../../devel/gmock/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
