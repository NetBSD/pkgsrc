# $NetBSD: Makefile,v 1.51 2022/07/02 16:53:16 ryoon Exp $

DISTNAME=	bitcoin-22.0
PKGREVISION=	6
CATEGORIES=	finance
MASTER_SITES=	https://bitcoincore.org/bin/bitcoin-core-${PKGVERSION_NOREV}/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/bitcoin/bitcoin
COMMENT=	P2P electronic cash system
LICENSE=	mit

RCD_SCRIPTS=	bitcoind

USE_LANGUAGES=		c c++
GCC_REQD+=		7 # C++17
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-ccache
CONFIGURE_ARGS+=	--disable-hardening # uses -fPIE which is problemtic
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
PKGCONFIG_OVERRIDE=	libbitcoinconsensus.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

# This package will link against libstdc++.so from the pkgsrc GCC when the
# base OS GCC doesn't meet the minimum requirement. Thus we do this so the
# appropriate gcc-libs package will be captured as a dependency, otherwise
# binary packages will be broken.
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 090000
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.endif

.if ${OS_VARIANT} == "SmartOS"
CONFIGURE_ARGS+=	--disable-tests
.endif

# pkgsrc's db4 package installs as db4_, but bitcoin looks for db_.
BUILDLINK_TRANSFORM+=	l:db_cxx:db4_cxx

# TODO: Decide if secp256k1 and univalue are supposed to be installed,
# and if so where, or if they should be linked with privately.
INSTALL_DIRS=	${BUILD_DIRS} src/secp256k1 src/univalue

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.21
.include "../../devel/libevent/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
