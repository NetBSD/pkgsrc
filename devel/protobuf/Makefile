# $NetBSD: Makefile,v 1.54 2022/01/30 16:33:43 adam Exp $
#
# When updating this, please also update devel/py-protobuf
#
# Please note: this package often changes the major version
# number of libraries, so please compare binary packages
# from before and after, and do a recursive PKGREVISION
# bump if necessary

DISTNAME=	protobuf-cpp-3.19.4
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

# configure: error: *** A compiler with support for C++11 language features is required.
GCC_REQD+=	4.8

# included in third_party
#.include "../../devel/googletest/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
