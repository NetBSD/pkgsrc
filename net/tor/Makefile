# $NetBSD: Makefile,v 1.89 2012/09/13 17:09:01 drochner Exp $
#

DISTNAME=		tor-0.2.2.39
CATEGORIES=		net security
MASTER_SITES=		http://www.torproject.org/dist/
# MASTER_SITES redirects to https, and ftp(1) cannot handle that.
FETCH_USING=		curl

MAINTAINER=		athaba@users.sourceforge.net
HOMEPAGE=		http://www.torproject.org/
COMMENT=		Anonymizing overlay network for TCP
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c99
# tor is not documented to require GNU make, but it fails to build on
# NetBSD 5.1 with (system) BSD make.  Reported to
# tor-talk@lists.torproject.org on 20110907.
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		CPP=${CPP:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

TEST_TARGET=		check

TOR_USER?=		tor
TOR_GROUP?=		tor
PKG_HOME?=		${VARBASE}/chroot/tor
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	tor

PKG_GROUPS_VARS+=	TOR_GROUP
PKG_USERS_VARS=		TOR_USER

RCD_SCRIPTS=		tor
RCD_SCRIPT_SRC.tor=	${FILESDIR}/tor.in
PKG_GROUPS=		${TOR_GROUP}
PKG_USERS=		${TOR_USER}:${TOR_GROUP}::Torifier:${PKG_HOME}
USER_GROUP=		${TOR_USER} ${TOR_GROUP}

OWN_DIRS_PERMS+=	${PKG_HOME} ${USER_GROUP} 0700

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONF_FILES+=		${PREFIX}/share/examples/tor/tor-tsocks.conf 	\
				${PKG_SYSCONFDIR}/tor-tsocks.conf
CONF_FILES+=		${PREFIX}/share/examples/tor/torrc.sample 	\
				${PKG_SYSCONFDIR}/torrc

FILES_SUBST+=		PKG_HOME=${PKG_HOME}
FILES_SUBST+=		TOR_USER=${TOR_USER} TOR_GROUP=${TOR_GROUP}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		contrib/torify.in
SUBST_SED.fix-paths=		-e 's,"/etc/tor,"${PKG_SYSCONFDIR},g'

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CHECK_PORTABILITY_SKIP+=contrib/*

.if !empty(PKGSRC_COMPILER:Mmipspro)
CFLAGS+=		-c99
.endif

BUILD_DEPENDS+= asciidoc-[0-9]*:../../textproc/asciidoc
BUILDLINK_API_DEPENDS.libevent+= libevent>=1.2
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

## We include this after other b3.mk files since we use PTHREAD_TYPE.
##
.include "options.mk"

.include "../../mk/bsd.pkg.mk"
