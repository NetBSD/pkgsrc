# $NetBSD: Makefile,v 1.1.1.1 2005/11/29 19:17:03 adrianp Exp $

DISTNAME=	Unreal3.2.3
PKGNAME=	unrealircd-3.2.3
CATEGORIES=	chat
MASTER_SITES=	http://unreal.atlanti-ka.org/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://www.unrealircd.com/
COMMENT=	Advanced IRC server with IPv6 and SSL support

CONFLICTS+=	ircu-[0-9]*

GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/Unreal3.2
TRE_NEEDED=	0.7.2

BUILDLINK_DEPENDS.tre+=	tre-${TRE_NEEDED}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=	tre_version=${TRE_NEEDED:Q}
CONFIGURE_ENV+=	TRELIBS="-L${PREFIX}/lib -ltre"

CONFIGURE_ARGS+=	--with-dpath=${UIRCD_HOME}
CONFIGURE_ARGS+=	--with-spath=${PREFIX}/sbin/ircd
CONFIGURE_ARGS+=	--with-permissions=0660
CONFIGURE_ARGS+=	--enable-dynamic-linking

CONFIGURE_ARGS+=	--with-hostname=${UIRCD_HOST}
CONFIGURE_ARGS+=	--enable-prefixaq
CONFIGURE_ARGS+=	--with-listen=${UIRCD_LISTEN}
CONFIGURE_ARGS+=	--with-sendq=${UIRCD_SENDQ}
CONFIGURE_ARGS+=	--with-bufferpool=${UIRCD_BUFFER}
CONFIGURE_ARGS+=	--with-fd-setsize=${UIRCD_FDSIZE}
CONFIGURE_ARGS+=	--with-nick-history=${UIRCD_NICKHIST}
CONFIGURE_ARGS+=	--disable-inet6

.include "options.mk"

IRCD_DOCS=	${PREFIX}/share/doc/unrealircd
IRCD_SHARE=	${PREFIX}/share/unrealircd
IRCD_EG=	${PREFIX}/share/examples/unrealircd

BUILD_DEFS+=	UIRCD_SENDQ UIRCD_LISTEN UIRCD_BUFFER UIRCD_USER UIRCD_HOST
BUILD_DEFS+=	UIRCD_HOME UIRCD_NICKHIST UIRCD_FDSIZE UIRCD_GROUP

PTHREAD_OPTS+=	require

# The defaults for most of these here are from the standard Conf
# script supplied with the UnrealIRCd package.
#
UIRCD_SENDQ?=		3000000
UIRCD_LISTEN?=		5
UIRCD_BUFFER?=		18
UIRCD_NICKHIST?=	2000
UIRCD_FDSIZE?=		512
UIRCD_USER?=		uircd
UIRCD_GROUP?=		uircd
UIRCD_HOST?=		localhost
UIRCD_HOME?=		${VARBASE}/unrealircd

DOC_FILES=	doc/Authors doc/coding-guidelines doc/tao.of.irc LICENSE

CONF_FILES_PERMS=	${IRCD_EG}/example.conf ${UIRCD_HOME}/unrealircd.conf \
			${UIRCD_USER} ${UIRCD_GROUP} 0660

PKG_USERS=	${UIRCD_USER}:${UIRCD_GROUP}::UnrealIRCD\ user:${UIRCD_HOME}:${NOLOGIN}
PKG_GROUPS=	${UIRCD_GROUP}
RCD_SCRIPTS=	unrealircd

MESSAGE_SRC+=	${WRKDIR}/.MESSAGE_SRC
MESSAGE_SUBST+=	UIRCD_HOME=${UIRCD_HOME}
FILES_SUBST+=	UIRCD_HOME=${UIRCD_HOME:Q}
FILES_SUBST+=	UIRCD_USER=${UIRCD_USER:Q}
FILES_SUBST+=	UIRCD_GROUP=${UIRCD_GROUP:Q}

SUBST_CLASSES+=		homedir
SUBST_STAGE.homedir=	post-patch
SUBST_FILES.homedir=	doc/example.conf
SUBST_SED.homedir=	-e "s|src/modules|${IRCD_SHARE}/modules|g" \
			-e "s|include \"|include \"${IRCD_SHARE}/|g"
SUBST_MESSAGE.homedir=	"Fixing home directory of IRC server."

OWN_DIRS_PERMS+=	${UIRCD_HOME} ${UIRCD_USER} ${UIRCD_GROUP} 0770
OWN_DIRS_PERMS+=	${UIRCD_HOME}/tmp ${UIRCD_USER} ${UIRCD_GROUP} 0770

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=YES
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/tre/buildlink3.mk"

post-build:
	@${CP} ${PKGDIR}/MESSAGE ${WRKDIR}/.MESSAGE_SRC
.if !empty(PKG_OPTIONS:Minet6)
	@${CP} ${PKGDIR}/MESSAGE.inet6 ${WRKDIR}/.MESSAGE_SRC.inet6
.endif

do-install:
	${INSTALL_DATA_DIR} ${IRCD_SHARE}
	${INSTALL_DATA_DIR} ${IRCD_SHARE}/networks
	${INSTALL_DATA_DIR} ${IRCD_SHARE}/aliases
	${INSTALL_DATA_DIR} ${IRCD_SHARE}/modules
	${INSTALL_DATA_DIR} ${IRCD_DOCS}
	${INSTALL_DATA_DIR} ${IRCD_EG}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/unrealircd

	${INSTALL_PROGRAM} ${WRKSRC}/src/ircd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/networks/*.network ${IRCD_SHARE}/networks
	${INSTALL_DATA} ${WRKSRC}/networks/networks.ndx ${IRCD_SHARE}/networks
	${INSTALL_SCRIPT} ${WRKSRC}/networks/makenet ${IRCD_SHARE}/networks
	${INSTALL_DATA} ${WRKSRC}/aliases/*.conf ${IRCD_SHARE}/aliases
	${INSTALL_DATA} ${WRKSRC}/badwords*.conf ${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/help.conf ${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/spamfilter.conf ${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/src/modules/*.so ${IRCD_SHARE}/modules

	for f in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${IRCD_DOCS}; \
	done

	${INSTALL_DATA} ${WRKSRC}/doc/unreal32docs.html \
		${PREFIX}/share/doc/html/unrealircd

	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${IRCD_EG}

.include "../../mk/bsd.pkg.mk"
