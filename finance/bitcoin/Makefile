# $NetBSD: Makefile,v 1.97 2025/10/03 07:37:04 adam Exp $

DISTNAME=	bitcoin-29.1
CATEGORIES=	finance
MASTER_SITES=	https://bitcoincore.org/bin/bitcoin-core-${PKGVERSION_NOREV}/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/bitcoin/bitcoin
COMMENT=	P2P electronic cash system
LICENSE=	mit

RCD_SCRIPTS=	bitcoind

USE_CXX_FEATURES+=	c++20 filesystem
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
CMAKE_CONFIGURE_ARGS+=	-DBUILD_BENCH=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_UTIL=ON
# Tests take a lot of time to compile.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TX=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WALLET_TOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_HARDENING=OFF # uses -fPIE which is problemtic
CMAKE_CONFIGURE_ARGS+=	-DWITH_BDB=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_CCACHE=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_ZMQ=ON
PKGCONFIG_OVERRIDE=	libbitcoinkernel.pc.in

.include "../../mk/bsd.prefs.mk"

# This package will link against libstdc++.so from the pkgsrc GCC when the
# base OS GCC doesn't meet the minimum requirement. Thus we do this so the
# appropriate gcc-libs package will be captured as a dependency, otherwise
# binary packages will be broken.
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 090000
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.endif

# pkgsrc's db4 package installs as db4_, but bitcoin looks for db_.
BUILDLINK_TRANSFORM+=	l:db_cxx:db4_cxx

# TODO: Decide if secp256k1 and univalue are supposed to be installed,
# and if so where, or if they should be linked with privately.
#INSTALL_DIRS=	${BUILD_DIRS} src/secp256k1 #src/univalue

.include "options.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.21
.include "../../devel/libevent/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
