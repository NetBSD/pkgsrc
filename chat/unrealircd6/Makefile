# $NetBSD: Makefile,v 1.7 2024/05/16 06:14:37 wiz Exp $

DISTNAME=	unrealircd-6.0.3
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	https://www.unrealircd.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unrealircd.org/
COMMENT=	Advanced IRC server with IPv6 and SSL support
LICENSE=	gnu-gpl-v2

CONFLICTS+=	ircu-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake gunzip pkg-config

.include "options.mk"

SUBST_CLASSES+=		argon2
SUBST_STAGE.argon2=	pre-configure
SUBST_MESSAGE.argon2=	Fixing Argon2 version number
SUBST_FILES.argon2+=	configure
SUBST_SED.argon2+=	-e 's|0~20161029|ZERO|g'

PKG_SYSCONFSUBDIR=	unrealircd

# Quoth ./configure,
# "noone knows if disabling dynamic linking actually does anything or not".
# Also needed to configure non-interactively.
CONFIGURE_ARGS+=	--enable-dynamic-linking

CONFIGURE_ARGS+=	--enable-ssl=${BUILDLINK_PREFIX.openssl}

CONFIGURE_ARGS+=	--with-system-cares
CONFIGURE_ARGS+=	--with-system-pcre2

CONFIGURE_ARGS+=	--with-permissions=0660
CONFIGURE_ARGS+=	--with-datadir=${VARBASE}/unrealircd
CONFIGURE_ARGS+=	--with-cachedir=${VARBASE}/cache/unrealircd
CONFIGURE_ARGS+=	--with-controlfile=${VARBASE}/run/unrealircd.ctl
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log/unrealircd
CONFIGURE_ARGS+=	--with-tmpdir=${VARBASE}/tmp/unrealircd
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/unrealircd.pid
CONFIGURE_ARGS+=	--with-scriptdir=${PREFIX}/share/unrealircd/scripts
CONFIGURE_ARGS+=	--with-bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--with-modulesdir=${PREFIX}/lib/unrealircd/modules
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/unrealircd
CONFIGURE_ARGS+=	--with-confdir=${PKG_SYSCONFDIR}

OWN_DIRS_PERMS+=	${VARBASE}/unrealircd ${UIRCD_USER} ${UIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/cache/unrealircd ${UIRCD_USER} ${UIRCD_GROUP} 0700
OWN_DIRS_PERMS+=	${VARBASE}/log/unrealircd ${UIRCD_USER} ${UIRCD_GROUP} 0700
OWN_DIRS_PERMS+=	${VARBASE}/run/unrealircd ${UIRCD_USER} ${UIRCD_GROUP} 0700
OWN_DIRS_PERMS+=	${VARBASE}/tmp/unrealircd ${UIRCD_USER} ${UIRCD_GROUP} 0700

CONFIGURE_ARGS+=	--with-nick-history=${UIRCD_NICKHIST:Q}

CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_create=no
CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_ctl=no
CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_wait=no

IRCD_EG=	${PREFIX}/share/examples/unrealircd

BUILD_DEFS+=	UIRCD_NICKHIST VARBASE

PTHREAD_OPTS+=	require

.include "../../mk/bsd.prefs.mk"

# The defaults for most of these here are from the standard Conf
# script supplied with the UnrealIRCd package.
#
UIRCD_NICKHIST?=	2000
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

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	lib/unrealircd/modules
INSTALLATION_DIRS+=	lib/unrealircd/modules/usermodes
INSTALLATION_DIRS+=	lib/unrealircd/modules/chanmodes
INSTALLATION_DIRS+=	lib/unrealircd/modules/extbans
INSTALLATION_DIRS+=	share/doc/unrealircd
INSTALLATION_DIRS+=	share/unrealircd/scripts
INSTALLATION_DIRS+=	${IRCD_EG}
INSTALLATION_DIRS+=	${IRCD_EG}/aliases
INSTALLATION_DIRS+=	${IRCD_EG}/help
INSTALLATION_DIRS+=	${IRCD_EG}/tls

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ircd ${DESTDIR}${PREFIX}/bin/unrealircd
	${INSTALL_DATA} ${WRKSRC}/doc/Authors ${DESTDIR}${PREFIX}/share/doc/unrealircd
	${INSTALL_DATA} ${WRKSRC}/doc/coding-guidelines ${DESTDIR}${PREFIX}/share/doc/unrealircd
	${INSTALL_DATA} ${WRKSRC}/doc/tao.of.irc ${DESTDIR}${PREFIX}/share/doc/unrealircd
	${INSTALL_DATA} ${WRKSRC}/doc/conf/*.conf ${DESTDIR}${IRCD_EG}
	${INSTALL_DATA} ${WRKSRC}/doc/conf/examples/*.conf ${DESTDIR}${IRCD_EG}
	${INSTALL_DATA} ${WRKSRC}/doc/conf/aliases/*.conf ${DESTDIR}${IRCD_EG}/aliases
	${INSTALL_DATA} ${WRKSRC}/doc/conf/help/*.conf ${DESTDIR}${IRCD_EG}/help
	${INSTALL_DATA} ${WRKSRC}/doc/conf/tls/curl-ca-bundle.crt ${DESTDIR}${IRCD_EG}/tls
	${INSTALL_SCRIPT} ${WRKSRC}/unrealircd ${DESTDIR}${PREFIX}/share/unrealircd/scripts
	${INSTALL_LIB} ${WRKSRC}/src/modules/*.so ${DESTDIR}${PREFIX}/lib/unrealircd/modules
	${INSTALL_LIB} ${WRKSRC}/src/modules/usermodes/*.so ${DESTDIR}${PREFIX}/lib/unrealircd/modules/usermodes
	${INSTALL_LIB} ${WRKSRC}/src/modules/chanmodes/*.so ${DESTDIR}${PREFIX}/lib/unrealircd/modules/chanmodes
	${INSTALL_LIB} ${WRKSRC}/src/modules/extbans/*.so ${DESTDIR}${PREFIX}/lib/unrealircd/modules/extbans

.include "../../net/libcares/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
