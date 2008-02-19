# $NetBSD: Makefile,v 1.52 2008/02/19 13:45:18 obache Exp $
#

DISTNAME=		tor-0.1.2.19
CATEGORIES=		net security
MASTER_SITES=		http://www.torproject.org/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.torproject.org/
COMMENT=		Anonymizing overlay network for TCP

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES+=		c99
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		CPP=${CPP:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}

TEST_TARGET=		check

TOR_USER?=		tor
TOR_GROUP?=		tor
PKG_HOME?=		${VARBASE}/chroot/tor
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	tor

PKG_GROUPS_VARS+=	TOR_GROUP
PKG_USERS_VARS+=	TOR_USER

RCD_SCRIPTS=		tor
RCD_SCRIPT_SRC.tor=	${FILESDIR}/tor.in
PKG_GROUPS=		${TOR_GROUP}
PKG_USERS=		${TOR_USER}:${TOR_GROUP}
PKG_GECOS.${TOR_USER}=	Torifier
PKG_HOME.${TOR_USER}=	${PKG_HOME}
USER_GROUP=		${TOR_USER} ${TOR_GROUP}

OWN_DIRS_PERMS+=	${PKG_HOME} ${USER_GROUP} 0700

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-libevent-dir=${BUILDLINK_PREFIX.libevent:Q}

CONF_FILES+=		${PREFIX}/share/examples/tor/tor-tsocks.conf 	\
				${PKG_SYSCONFDIR}/tor-tsocks.conf
CONF_FILES+=		${PREFIX}/share/examples/tor/torrc.sample 	\
				${PKG_SYSCONFDIR}/torrc

FILES_SUBST+=		PKG_HOME=${PKG_HOME:Q}
FILES_SUBST+=		TOR_USER=${TOR_USER:Q} TOR_GROUP=${TOR_GROUP:Q}

CHECK_PORTABILITY_SKIP+=contrib/*

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tor
	${INSTALL_DATA} ${WRKSRC}/src/config/torrc.sample		\
		${PREFIX}/share/examples/tor/torrc.sample
	${INSTALL_DATA} ${WRKSRC}/contrib/tor-tsocks.conf		\
		${PREFIX}/share/examples/tor/tor-tsocks.conf

BUILDLINK_API_DEPENDS.libevent+= libevent>=1.1a

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

## We include this after other b3.mk files since we use PTHREAD_TYPE.
##
.include "options.mk"

.include "../../mk/bsd.pkg.mk"
