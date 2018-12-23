# $NetBSD: Makefile,v 1.17 2018/12/23 23:51:26 tsutsui Exp $

.include "Makefile.common"

DISTNAME=	protobuf-cpp-${PROTOBUFVER}
PKGNAME=	${DISTNAME:S/-cpp//}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Google protocol buffers

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++11 c
USE_TOOLS+=	autoreconf automake autoconf gmake

SET_LIBDIR=	yes

PKGCONFIG_OVERRIDE+=	protobuf-lite.pc.in
PKGCONFIG_OVERRIDE+=	protobuf.pc.in

TEST_TARGET=	check

.if ${MACHINE_ARCH} == "i386"
# 64 bit atomic ops are required
CXXFLAGS+=	-march=i586
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

.include "../../devel/googletest/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
