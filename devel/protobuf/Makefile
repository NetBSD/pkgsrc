# $NetBSD: Makefile,v 1.35 2020/11/14 14:07:40 adam Exp $

DISTNAME=	protobuf-cpp-3.14.0
PKGNAME=	${DISTNAME:S/-cpp//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=protocolbuffers/}
GITHUB_PROJECT=	protobuf
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/protocolbuffers/protobuf
COMMENT=	Google protocol buffers
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME:S/-cpp//}

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	protobuf-lite.pc.in
PKGCONFIG_OVERRIDE+=	protobuf.pc.in
TEST_TARGET=		check

# false positive: the Makefile generates bash programs
CHECK_PORTABILITY_SKIP=		benchmarks/Makefile.in
# the [[ command will skip a test that would otherwise run
CHECK_PORTABILITY_SKIP+=	src/google/protobuf/compiler/zip_output_unittest.sh

SET_LIBDIR=	yes

.if ${MACHINE_ARCH} == "i386"
# 64 bit atomic ops are required
CXXFLAGS+=	-march=i586
.endif

# configure: error: *** A compiler with support for C++11 language features is required.
GCC_REQD+=	4.8

# included in third_party
#.include "../../devel/googletest/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
