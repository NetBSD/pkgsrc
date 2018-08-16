# $NetBSD: Makefile,v 1.54 2018/08/16 18:54:37 adam Exp $

DISTNAME=	Unreal3.2.10.5
PKGNAME=	${DISTNAME:tl:S/l/lircd-/1}
PKGREVISION=	9
CATEGORIES=	chat
MASTER_SITES=	http://unrealircd.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unrealircd.org/
COMMENT=	Advanced IRC server with IPv6 and SSL support
LICENSE=	gnu-gpl-v2

CONFLICTS+=	ircu-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake gunzip pkg-config

CHECK_PORTABILITY_SKIP=	update

.include "options.mk"

CONFIGURE_ARGS+=	--with-system-cares
CONFIGURE_ARGS+=	--with-system-tre

CONFIGURE_ARGS+=	--with-dpath=${UIRCD_HOME}
CONFIGURE_ARGS+=	--with-spath=${PREFIX}/sbin/ircd
CONFIGURE_ARGS+=	--with-permissions=0660

CONFIGURE_ARGS+=	--with-listen=${UIRCD_LISTEN:Q}
CONFIGURE_ARGS+=	--with-sendq=${UIRCD_SENDQ:Q}
CONFIGURE_ARGS+=	--with-bufferpool=${UIRCD_BUFFER:Q}
CONFIGURE_ARGS+=	--with-fd-setsize=${UIRCD_FDSIZE:Q}
CONFIGURE_ARGS+=	--with-nick-history=${UIRCD_NICKHIST:Q}

IRCD_DOCS=	${PREFIX}/share/doc/unrealircd
IRCD_SHARE=	${PREFIX}/share/unrealircd
IRCD_EG=	${PREFIX}/share/examples/unrealircd

BUILD_DEFS+=	UIRCD_SENDQ UIRCD_LISTEN UIRCD_BUFFER UIRCD_HOST
BUILD_DEFS+=	UIRCD_HOME UIRCD_NICKHIST UIRCD_FDSIZE VARBASE

PTHREAD_OPTS+=	require

.include "../../mk/bsd.prefs.mk"

# The defaults for most of these here are from the standard Conf
# script supplied with the UnrealIRCd package.
#
UIRCD_SENDQ?=		3000000
UIRCD_LISTEN?=		5
UIRCD_BUFFER?=		18
UIRCD_NICKHIST?=	2000
UIRCD_FDSIZE?=		1024
UIRCD_USER?=		uircd
UIRCD_GROUP?=		uircd
UIRCD_HOST?=		localhost
UIRCD_HOME?=		${VARBASE}/unrealircd

DOC_FILES=		doc/Authors doc/coding-guidelines doc/tao.of.irc LICENSE

CONF_FILES_PERMS=	${IRCD_EG}/example.conf \
			${UIRCD_HOME}/unrealircd.conf \
			${UIRCD_USER} ${UIRCD_GROUP} 0660

PKG_USERS_VARS+=	UIRCD_USER
PKG_GROUPS_VARS+=	UIRCD_GROUP

PKG_GROUPS=		${UIRCD_GROUP}
PKG_USERS=		${UIRCD_USER}:${UIRCD_GROUP}

PKG_GECOS.${UIRCD_USER}=	UnrealIRCD user
PKG_HOME.${UIRCD_USER}=		${UIRCD_HOME}

RCD_SCRIPTS=	unrealircd

FILES_SUBST+=	UIRCD_HOME=${UIRCD_HOME}
FILES_SUBST+=	UIRCD_USER=${UIRCD_USER}
FILES_SUBST+=	UIRCD_GROUP=${UIRCD_GROUP}

SUBST_CLASSES+=		homedir
SUBST_STAGE.homedir=	pre-configure
SUBST_FILES.homedir=	doc/example.conf
SUBST_SED.homedir=	-e "s|src/modules|${IRCD_SHARE}/modules|g"
SUBST_SED.homedir+=	-e "s|include \"|include \"${IRCD_SHARE}/|g"
SUBST_MESSAGE.homedir=	Fixing home directory of the IRC server.

.if !empty(PKG_OPTIONS:Munrealircd-chroot)
SUBST_CLASSES+=		chroot
SUBST_STAGE.chroot=	pre-install
SUBST_FILES.chroot=	${WRKDIR}/unrealircd
SUBST_SED.chroot=	-e "s|unrealircd_user=|\#unrealircd_user=|g"
SUBST_SED.chroot+=	-e "s|unrealircd_group=|\#unrealircd_group=|g"
SUBST_MESSAGE.chroot=	Fixing chroot installation.
.endif

OWN_DIRS_PERMS+=	${UIRCD_HOME}     ${UIRCD_USER} ${UIRCD_GROUP} 0770
OWN_DIRS_PERMS+=	${UIRCD_HOME}/tmp ${UIRCD_USER} ${UIRCD_GROUP} 0770
INSTALLATION_DIRS=	sbin ${IRCD_DOCS} ${IRCD_EG} ${IRCD_SHARE}/aliases \
			${IRCD_SHARE}/modules

CFLAGS.Darwin+=	-DUSE_LOCALE
CFLAGS.SunOS+=	-DUSE_LOCALE

.include "../../net/libcares/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/tre/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ircd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/aliases/*.conf \
		${DESTDIR}${IRCD_SHARE}/aliases
	${INSTALL_DATA} ${WRKSRC}/badwords*.conf ${DESTDIR}${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/help.* ${DESTDIR}${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/doc/help.* ${DESTDIR}${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/spamfilter.conf ${DESTDIR}${IRCD_SHARE}
	${INSTALL_LIB} ${WRKSRC}/src/modules/*.so \
		${DESTDIR}${IRCD_SHARE}/modules
	${INSTALL_DATA} ${WRKSRC}/doc/unreal32docs.* ${DESTDIR}${IRCD_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/example.* ${DESTDIR}${IRCD_EG}
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${IRCD_DOCS}
.endfor

.include "../../mk/bsd.pkg.mk"
