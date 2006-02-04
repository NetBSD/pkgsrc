# $NetBSD: Makefile,v 1.8 2006/02/04 21:13:54 adrianp Exp $

DISTNAME=	Unreal3.2.4
PKGNAME=	unrealircd-3.2.4
CATEGORIES=	chat
MASTER_SITES=	http://unrealircd.atlanti-ka.org/ \
		http://www.ilmarinen.us/unreal/ \
		http://www1.dnwt.net/unreal/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://www.unrealircd.com/
COMMENT=	Advanced IRC server with IPv6 and SSL support

CONFLICTS+=	ircu-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config gmake
WRKSRC=		${WRKDIR}/Unreal3.2
TRE_NEEDED=	0.7.2
CARES_NEEDED=	1.3.0

BUILDLINK_DEPENDS.tre+=	tre-${TRE_NEEDED}
BUILDLINK_DEPENDS.libcares+= libcares-${CARES_NEEDED}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=	tre_version=${TRE_NEEDED:Q}
CONFIGURE_ENV+=	TRELIBS="-L${PREFIX}/lib -ltre"
CONFIGURE_ENV+= cares_version=${CARES_NEEDED:Q}
CONFIGURE_ENV+= CARESINCDIR="${PREFIX}/include"
CONFIGURE_ENV+= CARESLIBS="-L${PREFIX}/lib -lcares"

CONFIGURE_ARGS+=	--with-dpath=${UIRCD_HOME:Q}
CONFIGURE_ARGS+=	--with-spath=${PREFIX}/sbin/ircd
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
UIRCD_FDSIZE?=		1024
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
MESSAGE_SUBST+=	UIRCD_HOME=${UIRCD_HOME:Q}
FILES_SUBST+=	UIRCD_HOME=${UIRCD_HOME:Q}
FILES_SUBST+=	UIRCD_USER=${UIRCD_USER:Q}
FILES_SUBST+=	UIRCD_GROUP=${UIRCD_GROUP:Q}

SUBST_CLASSES+=		homedir
SUBST_STAGE.homedir=	post-patch
SUBST_FILES.homedir=	doc/example.conf
SUBST_SED.homedir=	-e "s|src/modules|${IRCD_SHARE}/modules|g" \
			-e "s|include \"|include \"${IRCD_SHARE}/|g"
SUBST_MESSAGE.homedir=	Fixing home directory of the IRC server.

OWN_DIRS_PERMS+=	${UIRCD_HOME} ${UIRCD_USER} ${UIRCD_GROUP} 0770
OWN_DIRS_PERMS+=	${UIRCD_HOME}/tmp ${UIRCD_USER} ${UIRCD_GROUP} 0770

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=YES
.endif

.include "../../net/libcares/buildlink3.mk"
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
