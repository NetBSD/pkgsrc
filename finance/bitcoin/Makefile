# $NetBSD: Makefile,v 1.13 2019/07/01 04:08:08 ryoon Exp $

DISTNAME=	bitcoin-0.17.1
PKGREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=bitcoin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/bitcoin/bitcoin/
COMMENT=	P2P electronic cash system
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake
AUTO_MKDIRS=	yes
GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c++
# bitcoin-core requires c++11 (but does not need manual --std=c++11).

# TODO: File bug upstream - configure should add this where it is
# needed.  Without -fPIC, linking of test_bitcoin fails.
CFLAGS+=	-fPIC

# configure does not look in PREFIX for boost unless instructed.
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}

CONFIGURE_ARGS+=	--enable-hardening

.include "../../mk/bsd.prefs.mk"

.if ${OS_VARIANT} == "SmartOS"
CONFIGURE_ARGS+=	--disable-tests
.endif

# pkgsrc's db4 package installs as db4_, but bitcoin looks for db_.
BUILDLINK_TRANSFORM+=	l:db_cxx:db4_cxx

TEST_TARGET=	check

PLIST_VARS+=	qt

RCD_SCRIPTS=		bitcoind
BUILD_DEFS+=		VARBASE
OWN_DIRS=		${VARBASE}/bitcoin
EGDIR=			${PREFIX}/share/examples/bitcoin
CONF_FILES=		${EGDIR}/bitcoin.conf ${PKG_SYSCONFDIR}/bitcoin.conf
CONF_FILES_PERMS=	${EGDIR}/bitcoin.conf ${PKG_SYSCONFDIR}/bitcoin.conf ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644

# This is currently unnecessary, but it seems likely we will find a
# file that references /usr when ${PREFIX} is appropriate.
SUBST_CLASSES+=		pkg
SUBST_STAGE.pkg=	post-patch
SUBST_SED.pkg=		-e "s|/usr/|${PREFIX}/|g"
SUBST_MESSAGE.pkg=	Fixing /usr references to ${PREFIX}.

# bitcoin does not actually have releases; only snapshots of the
# repository from which a release would have been made.  Remedially
# create configure.in and similar.
pre-configure:
	cd ${WRKSRC} && ./autogen.sh

# TODO: Decide if secp256k1 and univalue are supposed to be installed,
# and if so where, or if they should be linked with privately.
INSTALL_DIRS=	${BUILD_DIRS} src/secp256k1 src/univalue

# Install the Debian example config file.
post-install:
	${INSTALL_DATA} -m 644 ${WRKSRC}/share/examples/bitcoin.conf ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
