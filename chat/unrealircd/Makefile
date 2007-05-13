# $NetBSD: Makefile,v 1.18 2007/05/13 21:15:58 adrianp Exp $

DISTNAME=	Unreal3.2.6
PKGNAME=	unrealircd-3.2.6
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://unrealircd.icedslash.com/ \
		http://www.blurryfox.com/unreal/ \
		http://unrealircd.pimpmylinux.org/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.unrealircd.com/
COMMENT=	Advanced IRC server with IPv6 and SSL support

CONFLICTS+=	ircu-[0-9]*

DIST_SUBDIR=	${PKGNAME}
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config gmake
WRKSRC=		${WRKDIR}/Unreal3.2
TRE_NEEDED=	0.7.2
CARES_NEEDED=	1.3.2

CHECK_PORTABILITY_SKIP=	update

BUILDLINK_API_DEPENDS.tre+=		tre-${TRE_NEEDED}
BUILDLINK_API_DEPENDS.libcares+=	libcares-${CARES_NEEDED}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=		tre_version=${TRE_NEEDED:Q}
CONFIGURE_ENV+=		TRELIBS='-L${PREFIX:Q}/lib -ltre'
CONFIGURE_ENV+=		cares_version=${CARES_NEEDED:Q}
CONFIGURE_ENV+=		CARESINCDIR='${PREFIX:Q}/include'
CONFIGURE_ENV+=		CARESLIBDIR='-L${PREFIX:Q}/lib'
CONFIGURE_ENV+=		CARESLIBS='-lcares'

CONFIGURE_ARGS+=	--with-dpath=${UIRCD_HOME:Q}
CONFIGURE_ARGS+=	--with-spath=${PREFIX:Q}/sbin/ircd
CONFIGURE_ARGS+=	--with-permissions=0660
CONFIGURE_ARGS+=	--enable-dynamic-linking

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

BUILD_DEFS+=	UIRCD_SENDQ UIRCD_LISTEN UIRCD_BUFFER UIRCD_USER UIRCD_HOST
BUILD_DEFS+=	UIRCD_HOME UIRCD_NICKHIST UIRCD_FDSIZE UIRCD_GROUP VARBASE

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

PKG_GROUPS=	${UIRCD_GROUP:Q}
PKG_USERS=	${UIRCD_USER:Q}:${UIRCD_GROUP:Q}

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

OWN_DIRS_PERMS+=	${UIRCD_HOME:Q} ${UIRCD_USER:Q} ${UIRCD_GROUP:Q} 0770
OWN_DIRS_PERMS+=	${UIRCD_HOME:Q}/tmp ${UIRCD_USER:Q} \
			${UIRCD_GROUP:Q} 0770

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=YES
.endif

.include "../../net/libcares/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/tre/buildlink3.mk"

post-build:
	${CP} ${PKGDIR:Q}/MESSAGE ${WRKDIR:Q}/.MESSAGE_SRC
.if !empty(PKG_OPTIONS:Minet6)
	${CP} ${PKGDIR:Q}/MESSAGE.inet6 ${WRKDIR:Q}/.MESSAGE_SRC.inet6
.endif

do-install:
	${INSTALL_DATA_DIR} ${IRCD_SHARE}
	${INSTALL_DATA_DIR} ${IRCD_SHARE:Q}/networks
	${INSTALL_DATA_DIR} ${IRCD_SHARE:Q}/aliases
	${INSTALL_DATA_DIR} ${IRCD_SHARE:Q}/modules
	${INSTALL_DATA_DIR} ${IRCD_DOCS:Q}
	${INSTALL_DATA_DIR} ${IRCD_EG:Q}

	${INSTALL_PROGRAM} ${WRKSRC:Q}/src/ircd ${PREFIX:Q}/sbin
	${INSTALL_DATA} ${WRKSRC:Q}/networks/*.network ${IRCD_SHARE:Q}/networks
	${INSTALL_DATA} ${WRKSRC:Q}/networks/networks.ndx \
		${IRCD_SHARE:Q}/networks
	${INSTALL_SCRIPT} ${WRKSRC:Q}/networks/makenet ${IRCD_SHARE:Q}/networks
	${INSTALL_DATA} ${WRKSRC:Q}/aliases/*.conf ${IRCD_SHARE:Q}/aliases
	${INSTALL_DATA} ${WRKSRC:Q}/badwords*.conf ${IRCD_SHARE:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/help.* ${IRCD_SHARE:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/doc/help.* ${IRCD_SHARE:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/spamfilter.conf ${IRCD_SHARE:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/src/modules/*.so ${IRCD_SHARE:Q}/modules
	${INSTALL_DATA} ${WRKSRC:Q}/doc/unreal32docs.* ${IRCD_DOCS:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/doc/example.* ${IRCD_EG:Q}

.	for f in ${DOC_FILES}
		${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${IRCD_DOCS:Q}
.	endfor

.include "../../mk/bsd.pkg.mk"
