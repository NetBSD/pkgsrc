# $NetBSD: Makefile,v 1.60 2019/07/01 04:07:59 ryoon Exp $

DISTNAME=	unrealircd-4.2.2
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	https://www.unrealircd.org/unrealircd4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unrealircd.org/
COMMENT=	Advanced IRC server with IPv6 and SSL support
LICENSE=	gnu-gpl-v2

CONFLICTS+=	ircu-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	aclocal autoconf autoheader automake bash
USE_TOOLS+=	gmake gunzip pkg-config

# 4.2.2 tarball was changed, remove on next update
DIST_SUBDIR=	unrealircd-20190402

.include "options.mk"

# Quoth ./configure,
# "noone knows if disabling dynamic linking actually does anything or not".
# Also needed to configure non-interactively.
CONFIGURE_ARGS+=	--enable-dynamic-linking

# not building without SSL is apparently unsupported but this still
# seems to be required or the build breaks...
CONFIGURE_ARGS+=	--enable-ssl

CONFIGURE_ARGS+=	--with-system-cares
CONFIGURE_ARGS+=	--with-system-tre
CONFIGURE_ARGS+=	--with-system-pcre2

CONFIGURE_ARGS+=	--with-permissions=0660
CONFIGURE_ARGS+=	--with-datadir=${PREFIX}/unrealircd/data
CONFIGURE_ARGS+=	--with-cachedir=${PREFIX}/unrealircd/cache
CONFIGURE_ARGS+=	--with-logdir=${PREFIX}/unrealircd/logs
CONFIGURE_ARGS+=	--with-tmpdir=${PREFIX}/unrealircd/tmp
CONFIGURE_ARGS+=	--with-pidfile=${PREFIX}/unrealircd/ircd.pid
CONFIGURE_ARGS+=	--with-scriptdir=${PREFIX}/unrealircd/scripts
CONFIGURE_ARGS+=	--with-bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--with-modulesdir=${PREFIX}/lib/unrealircd/modules
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/unrealircd
CONFIGURE_ARGS+=	--with-confdir=${PKG_SYSCONFDIR}/unrealircd

OWN_DIRS_PERMS+=	${PREFIX}/unrealircd ${UIRCD_USER} ${UIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/unrealircd/data ${UIRCD_USER} ${UIRCD_GROUP} 0700
OWN_DIRS_PERMS+=	${PREFIX}/unrealircd/cache ${UIRCD_USER} ${UIRCD_GROUP} 0700
OWN_DIRS_PERMS+=	${PREFIX}/unrealircd/logs ${UIRCD_USER} ${UIRCD_GROUP} 0700
OWN_DIRS_PERMS+=	${PREFIX}/unrealircd/tmp ${UIRCD_USER} ${UIRCD_GROUP} 0700

CONFIGURE_ARGS+=	--with-sendq=${UIRCD_SENDQ:Q}
CONFIGURE_ARGS+=	--with-fd-setsize=${UIRCD_FDSIZE:Q}
CONFIGURE_ARGS+=	--with-nick-history=${UIRCD_NICKHIST:Q}

IRCD_EG=	${PREFIX}/share/examples/unrealircd

BUILD_DEFS+=	UIRCD_SENDQ UIRCD_NICKHIST UIRCD_FDSIZE VARBASE

PTHREAD_OPTS+=	require

.include "../../mk/bsd.prefs.mk"

# The defaults for most of these here are from the standard Conf
# script supplied with the UnrealIRCd package.
#
UIRCD_SENDQ?=		3000000
UIRCD_NICKHIST?=	2000
UIRCD_FDSIZE?=		1024
UIRCD_USER?=		uircd
UIRCD_GROUP?=		uircd

PKG_USERS_VARS+=	UIRCD_USER
PKG_GROUPS_VARS+=	UIRCD_GROUP

PKG_GROUPS=		${UIRCD_GROUP}
PKG_USERS=		${UIRCD_USER}:${UIRCD_GROUP}

PKG_GECOS.${UIRCD_USER}=	UnrealIRCD user

RCD_SCRIPTS=	unrealircd

FILES_SUBST+=	UIRCD_USER=${UIRCD_USER}
FILES_SUBST+=	UIRCD_GROUP=${UIRCD_GROUP}

CFLAGS.Darwin+=	-DUSE_LOCALE
CFLAGS.SunOS+=	-DUSE_LOCALE

INSTALLATION_DIRS+=	unrealircd/scripts
INSTALLATION_DIRS+=	${IRCD_EG}

pre-configure:
	cd ${WRKSRC} && ${BASH} ./autogen.sh

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/unrealircd/* ${DESTDIR}${IRCD_EG}

.include "../../net/libcares/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/tre/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
