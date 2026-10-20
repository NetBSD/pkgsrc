# $NetBSD: Makefile,v 1.44 2026/10/20 18:34:46 adam Exp $

DISTNAME=	libtorrent-rasterbar-2.1.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=arvidn/}
GITHUB_PROJECT=	libtorrent
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libtorrent.org/
COMMENT=	Feature complete C++ bittorrent implementation
LICENSE=	modified-bsd

# Use GNU language variant to get builtin alloca definition.
USE_LANGUAGES=	c gnu++14
USE_TOOLS+=	pkg-config

# For deps/libdatachannel/CMakeLists.txt
CMAKE_CONFIGURE_ARGS+=	-DNO_EXAMPLES=ON
CMAKE_CONFIGURE_ARGS+=	-DNO_TESTS=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_JSON=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_SRTP=ON

PKGCONFIG_OVERRIDE+=	libtorrent-rasterbar.pc.in

.include "../../comms/srtp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
