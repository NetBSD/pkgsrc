# $NetBSD: Makefile,v 1.60 2026/08/03 19:42:41 wiz Exp $

DISTNAME=	libssh-0.12.1
CATEGORIES=	security
MASTER_SITES=	https://www.libssh.org/files/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	https://www.libssh.org/
COMMENT=	SSHv2+v1 protocol library
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	libssh.pc.cmake
TEST_TARGET=		test

CMAKE_CONFIGURE_ARGS+=	-DWITH_EXAMPLES=OFF

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS
LDFLAGS.SunOS+=		-lnsl -lsocket

BUILDLINK_TRANSFORM+=	rm:-Werror=strict-overflow

.include "options.mk"

.include "../../devel/cmake/build.mk"
# for examples only
BUILDLINK_DEPMETHOD.argp=  build
.include "../../devel/argp/buildlink3.mk"
# for testing only
BUILDLINK_DEPMETHOD.cmocka=  build
.include "../../devel/cmocka/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
