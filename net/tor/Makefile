# $NetBSD: Makefile,v 1.152 2020/03/18 16:43:49 wiz Exp $

DISTNAME=	tor-0.4.2.7
CATEGORIES=	net security
MASTER_SITES=	https://dist.torproject.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.torproject.org/
COMMENT=	Anonymizing overlay network for TCP
LICENSE=	modified-bsd

USE_LANGUAGES=		c99
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:test pkg-config
# There are multiple reports of failure to build with BSD make, due to
# an apparent lack of firing the rule to create micro-revision.i.
# Work around this by using gmake, which is tiny compared to the
# existing perl dependency, and unlikely to be needed on any given
# system just for tor.
USE_TOOLS+=		gmake bash:test
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ENV+=		CPP=${CPP:Q}

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

CONF_FILES+=		${PREFIX}/share/examples/tor/torrc.sample \
			${PKG_SYSCONFDIR}/torrc

PRINT_PLIST_AWK+=	/^man\/man/ { $$0 = "$${PLIST.doc}" $$0 }
PRINT_PLIST_AWK+=	/^share\/doc/ { $$0 = "$${PLIST.doc}" $$0 }

FILES_SUBST+=		PKG_HOME=${PKG_HOME.${TOR_USER}}
FILES_SUBST+=		TOR_USER=${TOR_USER} TOR_GROUP=${TOR_GROUP}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CHECK_PORTABILITY_SKIP+=	contrib/*

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro)
CFLAGS+=		-c99
.endif

.include "../../archivers/zstd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+= libevent>=2.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
