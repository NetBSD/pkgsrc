# $NetBSD: Makefile,v 1.35 2012/12/16 01:52:00 obache Exp $

DISTNAME=	Unreal3.2.9
PKGNAME=	unrealircd-3.2.9
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://unrealircd.com/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unrealircd.com/
COMMENT=	Advanced IRC server with IPv6 and SSL support

CONFLICTS+=	ircu-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config gmake

CHECK_PORTABILITY_SKIP=	update

WRKSRC=		${WRKDIR}/Unreal3.2

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-system-cares
CONFIGURE_ARGS+=	--with-system-tre

CONFIGURE_ARGS+=	--with-dpath=${UIRCD_HOME:Q}
CONFIGURE_ARGS+=	--with-spath=${PREFIX:Q}/sbin/ircd
CONFIGURE_ARGS+=	--with-permissions=0660

CONFIGURE_ARGS+=	--with-hostname=${UIRCD_HOST:Q}
CONFIGURE_ARGS+=	--with-listen=${UIRCD_LISTEN:Q}
CONFIGURE_ARGS+=	--with-sendq=${UIRCD_SENDQ:Q}
CONFIGURE_ARGS+=	--with-bufferpool=${UIRCD_BUFFER:Q}
CONFIGURE_ARGS+=	--with-fd-setsize=${UIRCD_FDSIZE:Q}
CONFIGURE_ARGS+=	--with-nick-history=${UIRCD_NICKHIST:Q}
CONFIGURE_ARGS+=	--disable-inet6

.include "options.mk"

IRCD_DOCS=	${PREFIX:Q}/share/doc/unrealircd
IRCD_SHARE=	${PREFIX:Q}/share/unrealircd
IRCD_EG=	${PREFIX:Q}/share/examples/unrealircd

BUILD_DEFS+=	UIRCD_SENDQ UIRCD_LISTEN UIRCD_BUFFER UIRCD_HOST
BUILD_DEFS+=	UIRCD_HOME UIRCD_NICKHIST UIRCD_FDSIZE VARBASE

PTHREAD_OPTS+=	require

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

CONF_FILES_PERMS=	${IRCD_EG:Q}/example.conf \
			${UIRCD_HOME:Q}/unrealircd.conf \
			${UIRCD_USER} ${UIRCD_GROUP} 0660

PKG_USERS_VARS+=	UIRCD_USER
PKG_GROUPS_VARS+=	UIRCD_GROUP

PKG_GROUPS=		${UIRCD_GROUP:Q}
PKG_USERS=		${UIRCD_USER:Q}:${UIRCD_GROUP:Q}

PKG_GECOS.${UIRCD_USER}=	UnrealIRCD user
PKG_HOME.${UIRCD_USER}=		${UIRCD_HOME}

RCD_SCRIPTS=	unrealircd

MESSAGE_SRC+=	${WRKDIR}/.MESSAGE_SRC
MESSAGE_SUBST+=	UIRCD_HOME=${UIRCD_HOME:Q}
FILES_SUBST+=	UIRCD_HOME=${UIRCD_HOME:Q}
FILES_SUBST+=	UIRCD_USER=${UIRCD_USER:Q}
FILES_SUBST+=	UIRCD_GROUP=${UIRCD_GROUP:Q}

SUBST_CLASSES+=		homedir
SUBST_STAGE.homedir=	post-patch
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

OWN_DIRS_PERMS+=	${UIRCD_HOME:Q} ${UIRCD_USER:Q} ${UIRCD_GROUP:Q} 0770
OWN_DIRS_PERMS+=	${UIRCD_HOME:Q}/tmp ${UIRCD_USER:Q} \
			${UIRCD_GROUP:Q} 0770
INSTALLATION_DIRS=	sbin ${IRCD_DOCS} ${IRCD_EG} ${IRCD_SHARE}/aliases \
			${IRCD_SHARE}/modules ${IRCD_SHARE}/networks

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=YES
.endif

CFLAGS.SunOS+=	-DUSE_LOCALE

.include "../../net/libcares/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/tre/buildlink3.mk"

post-build:
	${CP} ${PKGDIR:Q}/MESSAGE ${WRKDIR:Q}/.MESSAGE_SRC
.if !empty(PKG_OPTIONS:Minet6)
	${CP} ${PKGDIR:Q}/MESSAGE.inet6 ${WRKDIR:Q}/.MESSAGE_SRC.inet6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/src/ircd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC:Q}/networks/*.network \
		${DESTDIR}${IRCD_SHARE:Q}/networks
	${INSTALL_DATA} ${WRKSRC:Q}/networks/networks.ndx \
		${DESTDIR}${IRCD_SHARE:Q}/networks
	${INSTALL_SCRIPT} ${WRKSRC:Q}/networks/makenet \
		${DESTDIR}${IRCD_SHARE:Q}/networks
	${INSTALL_DATA} ${WRKSRC:Q}/aliases/*.conf \
		${DESTDIR}${IRCD_SHARE:Q}/aliases
	${INSTALL_DATA} ${WRKSRC:Q}/badwords*.conf ${DESTDIR}${IRCD_SHARE:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/help.* ${DESTDIR}${IRCD_SHARE:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/doc/help.* ${DESTDIR}${IRCD_SHARE:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/spamfilter.conf ${DESTDIR}${IRCD_SHARE:Q}
	${INSTALL_LIB} ${WRKSRC:Q}/src/modules/*.so \
		${DESTDIR}${IRCD_SHARE:Q}/modules
	${INSTALL_DATA} ${WRKSRC:Q}/doc/unreal32docs.* ${DESTDIR}${IRCD_DOCS:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/doc/example.* ${DESTDIR}${IRCD_EG:Q}

.	for f in ${DOC_FILES}
		${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${DESTDIR}${IRCD_DOCS:Q}
.	endfor

.include "../../mk/bsd.pkg.mk"
