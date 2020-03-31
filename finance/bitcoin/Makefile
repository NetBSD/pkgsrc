# $NetBSD: Makefile,v 1.22 2020/03/31 16:14:05 adam Exp $

DISTNAME=	bitcoin-0.19.1
CATEGORIES=	finance
MASTER_SITES=	https://bitcoincore.org/bin/bitcoin-core-${PKGVERSION_NOREV}/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/bitcoin/bitcoin
COMMENT=	P2P electronic cash system
LICENSE=	mit

# bitcoin-core requires c++11 (but does not need manual -std=c++11).
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-ccache
CONFIGURE_ARGS+=	--disable-hardening # uses -fPIE which is problemtic
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
PKGCONFIG_OVERRIDE=	libbitcoinconsensus.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${OS_VARIANT} == "SmartOS"
CONFIGURE_ARGS+=	--disable-tests
.endif

# pkgsrc's db4 package installs as db4_, but bitcoin looks for db_.
BUILDLINK_TRANSFORM+=	l:db_cxx:db4_cxx

# TODO: Decide if secp256k1 and univalue are supposed to be installed,
# and if so where, or if they should be linked with privately.
INSTALL_DIRS=	${BUILD_DIRS} src/secp256k1 src/univalue

.include "options.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
