# $NetBSD: Makefile,v 1.44 2023/01/24 18:36:32 wiz Exp $
#
# history: upstream renamed 0.11 to 0.1.1;
# we have to use the old-style convention so that version compares work.

VER=		0.9.6
DISTNAME=	libssh-${VER}
PKGNAME=	libssh-0.96
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://www.libssh.org/files/${VER:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	https://www.libssh.org/
COMMENT=	SSHv2+v1 protocol library
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	libssh.pc.cmake
TEST_TARGET=		test

CMAKE_ARGS+=		-DUNIT_TESTING=ON
CMAKE_ARGS+=		-DWITH_EXAMPLES=OFF

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
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
