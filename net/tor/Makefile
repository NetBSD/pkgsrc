# $NetBSD: Makefile,v 1.71 2010/03/02 11:25:59 obache Exp $
#

DISTNAME=		tor-0.2.1.24
CATEGORIES=		net security
MASTER_SITES=		http://www.torproject.org/dist/

MAINTAINER=		athaba@inode.at
HOMEPAGE=		http://www.torproject.org/
COMMENT=		Anonymizing overlay network for TCP
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

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
PKG_USERS=		${TOR_USER}:${TOR_GROUP}::Torifier:${PKG_HOME}
USER_GROUP=		${TOR_USER} ${TOR_GROUP}

OWN_DIRS_PERMS+=	${PKG_HOME} ${USER_GROUP} 0700

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}

CONF_FILES+=		${PREFIX}/share/examples/tor/tor-tsocks.conf 	\
				${PKG_SYSCONFDIR}/tor-tsocks.conf
CONF_FILES+=		${PREFIX}/share/examples/tor/torrc.sample 	\
				${PKG_SYSCONFDIR}/torrc

FILES_SUBST+=		PKG_HOME=${PKG_HOME:Q}
FILES_SUBST+=		TOR_USER=${TOR_USER:Q} TOR_GROUP=${TOR_GROUP:Q}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CHECK_PORTABILITY_SKIP+=contrib/*

.if !empty(PKGSRC_COMPILER:Mmipspro)
CFLAGS+=		-c99
.endif

BUILDLINK_API_DEPENDS.libevent+= libevent>=1.2
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

## We include this after other b3.mk files since we use PTHREAD_TYPE.
##
.include "options.mk"

.include "../../mk/bsd.pkg.mk"
