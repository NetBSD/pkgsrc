# $NetBSD: Makefile,v 1.109 2016/03/05 11:29:12 jperkin Exp $

DISTNAME=		tor-0.2.7.6
PKGREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		http://www.torproject.org/dist/

MAINTAINER=		athaba@users.sourceforge.net
HOMEPAGE=		http://www.torproject.org/
COMMENT=		Anonymizing overlay network for TCP
LICENSE=		modified-bsd

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c99
USE_PKGLOCALEDIR=	yes
# https://trac.torproject.org/projects/tor/ticket/17818
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		CPP=${CPP:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

TEST_TARGET=		check

TOR_USER?=		tor
TOR_GROUP?=		tor
PKG_GECOS.${TOR_USER}=	Torifier
PKG_HOME.${TOR_USER}=	${VARBASE}/chroot/tor
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	tor

PKG_GROUPS_VARS+=	TOR_GROUP
PKG_USERS_VARS=		TOR_USER

RCD_SCRIPTS=		tor
RCD_SCRIPT_SRC.tor=	${FILESDIR}/tor.in
PKG_GROUPS=		${TOR_GROUP}
PKG_USERS=		${TOR_USER}:${TOR_GROUP}
USER_GROUP=		${TOR_USER} ${TOR_GROUP}

OWN_DIRS_PERMS+=	${PKG_HOME.${TOR_USER}} ${USER_GROUP} 0700

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONF_FILES+=		${PREFIX}/share/examples/tor/torrc.sample 	\
				${PKG_SYSCONFDIR}/torrc

FILES_SUBST+=		PKG_HOME=${PKG_HOME.${TOR_USER}}
FILES_SUBST+=		TOR_USER=${TOR_USER} TOR_GROUP=${TOR_GROUP}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CHECK_PORTABILITY_SKIP+=contrib/*

.if !empty(PKGSRC_COMPILER:Mmipspro)
CFLAGS+=		-c99
.endif

BUILDLINK_API_DEPENDS.libevent+= libevent>=2.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.0
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

## We include this after other b3.mk files since we use PTHREAD_TYPE.
##
.include "options.mk"

.include "../../mk/bsd.pkg.mk"
