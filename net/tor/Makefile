# $NetBSD: Makefile,v 1.179 2022/06/17 14:53:59 wiz Exp $

DISTNAME=	tor-0.4.7.8
CATEGORIES=	net security
MASTER_SITES=	https://dist.torproject.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.torproject.org/
COMMENT=	Anonymizing overlay network for TCP
LICENSE=	modified-bsd

USE_LANGUAGES=		c99
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:test pkg-config bash:test
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ENV+=		CPP=${CPP:Q}
CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFDIR}

# https://gitlab.torproject.org/tpo/core/tor/-/issues/29520
# Without this workaround, fails reliable with MAKE_JOBS=1 on
# netbsd-9 amd64.
BUILD_TARGET=		micro-revision.i all

#============================================================================
#Testsuite summary for tor 0.4.6.6
#============================================================================
## TOTAL: 33
## PASS:  29
## SKIP:  4
## XFAIL: 0
## FAIL:  0
## XPASS: 0
## ERROR: 0
#============================================================================
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

REPLACE_BASH+=		scripts/maint/checkShellScripts.sh
REPLACE_BASH+=		scripts/maint/run_check_subsystem_order.sh

REPLACE_PERL+=		scripts/maint/checkOptionDocs.pl.in
REPLACE_PERL+=		scripts/maint/checkSpace.pl
REPLACE_PERL+=		scripts/coccinelle/test-operator-cleanup

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro)
CFLAGS+=		-c99
.endif

.include "../../archivers/zstd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+= libevent>=2.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
