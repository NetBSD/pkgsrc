# $NetBSD: Makefile,v 1.20 2005/09/27 19:53:41 tv Exp $
#

DISTNAME=		tor-0.1.0.15
CATEGORIES=		net security
MASTER_SITES=		http://tor.eff.org/dist/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://tor.eff.org/
COMMENT=		Anonymizing overlay network for TCP

.include "../../mk/bsd.prefs.mk"

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

TOR_USER?=		tor
TOR_GROUP?=		tor
PKG_HOME?=		/var/chroot/tor

USE_PKGINSTALL=		yes
RCD_SCRIPTS=            tor
PKG_GROUPS=		${TOR_GROUP}
PKG_USERS=              ${TOR_USER}:${TOR_GROUP}::Torifier:${PKG_HOME}
USER_GROUP=		${TOR_USER} ${TOR_GROUP}

OWN_DIR_PERMS+=		${PKG_HOME} ${USER_GROUP} 0755

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONF_FILES+=		${PREFIX}/share/examples/tor/tor-tsocks.conf 	\
				${PKG_SYSCONFDIR}/tor/tor-tsocks.conf
CONF_FILES+=		${PREFIX}/share/examples/tor/torrc.sample 	\
				${PKG_SYSCONFDIR}/tor/torrc

RCD_SCRIPT=		tor

INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

FILES_SUBST+=		PKG_HOME=${PKG_HOME}
FILES_SUBST+=		TOR_USER=${TOR_USER} TOR_GROUP=${TOR_GROUP}

.if !empty(PKGSRC_COMPILER:Mmipspro)
CFLAGS+=		-c99
.endif

post-patch:
	${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'		\
		-e 's|@PREFIX@|${PREFIX}|g' 				\
		-e 's|@PKG_HOME@|${PKG_HOME}|g'				\
		-e 's|@TOR_USER@|${TOR_USER}|g'				\
		-e 's|@TOR_GROUP@|${TOR_GROUP}|g'			\
		-e 's|@RCD_SCRIPTS_SHELL@|${RCD_SCRIPTS_SHELL}|g'	\
		${FILESDIR}/tor.in > ${WRKSRC}/tor.pkgsrc.rc

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/tor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tor
	${INSTALL_DATA} ${WRKSRC}/src/config/torrc.sample		\
		${PREFIX}/share/examples/tor/torrc.sample
	${INSTALL_DATA} ${WRKSRC}/contrib/tor-tsocks.conf		\
		${PREFIX}/share/examples/tor/tor-tsocks.conf
	${INSTALL_DATA_DIR} ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tor.pkgsrc.rc ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}/tor

BUILDLINK_DEPENDS.libevent+= libevent>=1.1a
# XXX the pkgsrc libevent builtin.mk does not detect the version of a builtin
# libevent, so we need to force use of the pkgsrc one
USE_BUILTIN.libevent=	no
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
