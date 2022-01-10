# $NetBSD: Makefile,v 1.46 2022/01/10 01:46:30 ryoon Exp $

DISTNAME=	bitcoin-22.0
PKGREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	https://bitcoincore.org/bin/bitcoin-core-${PKGVERSION_NOREV}/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/bitcoin/bitcoin
COMMENT=	P2P electronic cash system
LICENSE=	mit

RCD_SCRIPTS=	bitcoind

# bitcoin-core requires c++11 (but does not need manual -std=c++11).
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake gmake pkg-config
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
