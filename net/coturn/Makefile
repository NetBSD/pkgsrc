# $NetBSD: Makefile,v 1.5 2025/01/23 17:33:16 gdt Exp $

DISTNAME=	coturn-4.6.3
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=coturn/}

MAINTAINER=	kethzer.dr@gmail.com
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/coturn/coturn
COMMENT=	TURN and STUN server (for VoIP/webrtc)
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
HAS_CONFIGURE=		yes

# Set up to run as a non-root user, with a partitioned data directory.
COTURN_USER?=	coturn
COTURN_GROUP?=	${COTURN_USER}
COTURN_DATA?=	${VARBASE}/db/coturn
BUILD_DEFS+=	COTURN_USER COTURN_GROUP VARBASE COTURN_DATA

CONFIGURE_ARGS+=	--disable-rpath
CONFIGURE_ARGS+=	--localstatedir ${COTURN_DATA}
CONFIGURE_ARGS+=	--prefix ${PREFIX}

# Pass cflags/libs
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.libevent}/include"
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_LIBS="-L${BUILDLINK_PREFIX.libevent}/lib -levent_openssl -levent"

# \todo File a bug upstream, or explain why the warning is wrong.
CFLAGS+=	-Wno-stringop-truncation

COTURN_CONFIG=	${PKG_SYSCONFDIR}/turnserver.conf
COTURN_EGDIR=	${PREFIX}/share/examples/coturn
CONF_FILES=	${COTURN_EGDIR}/etc/turnserver.conf ${COTURN_CONFIG}

RCD_SCRIPTS=	turnserver

# Create the data directory, because the daemon can't due to dropping root.
OWN_DIRS_PERMS+=		${COTURN_DATA} ${COTURN_USER} ${COTURN_GROUP} 0770

PKG_USERS_VARS=			COTURN_USER
PKG_GROUPS_VARS=		COTURN_GROUP
PKG_GROUPS=			${COTURN_GROUP}
PKG_USERS=			${COTURN_USER}:${COTURN_GROUP}
PKG_GECOS.${COTURN_USER}=	coturn daemon user
PKG_HOME.${COTURN_USER}=	${COTURN_DATA}
PKG_SHELL.${COTURN_USER}=	${NOLOGIN}

FILES_SUBST+=	COTURN_USER=${COTURN_USER:Q}
FILES_SUBST+=	COTURN_GROUP=${COTURN_GROUP:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

# Use coturn as docs/examples subdir name.  \todo No command-line argument?
CONFIGURE_ENV+=		PORTNAME=coturn
# Defaults to ${PREFIX}/etc; respect pkgsrc tunable.
CONFIGURE_ARGS+=	--confdir=${PKG_SYSCONFDIR}
# Defaults to ${PREFIX}/var; give it a subdirectory.
CONFIGURE_ARGS+=	--localstatedir=${COTURN_DATA}

# \todo Why is there a db installed in /var?  If not within PREFIX we don't pick it up,
# but it seems like a bug.

.include "options.mk"

# upstream installs both a .conf.default in etcdir, and the
# pkgsrc-right-way .conf in egdir.
post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/turnserver.conf.default

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
