# $NetBSD: Makefile,v 1.1.1.1 2003/12/23 10:16:20 xtraeme Exp $
#

DISTNAME=		jabberd-1.4.3
CATEGORIES=		chat
MASTER_SITES=		http://jabberd.jabberstudio.org/1.4/dist/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://jabberd.jabberstudio.org/1.4/
COMMENT=		Instant messaging server

CONFLICTS=		jabberd2-[0-9]*:../../wip/jabberd2

USE_BUILDLINK2=		yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--enable-ssl

RCD_SCRIPTS=		jabberd
PKG_SYSCONFSUBDIR=	jabberd

EGDIR=			${PREFIX}/share/examples/jabberd
LIBDIR=			${PREFIX}/lib/jabberd
INCDIR=			${PREFIX}/include/jabberd

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		JABBERD_USER	JABBERD_GROUP \
			JABBERD_LOGDIR	JABBERD_SPOOLDIR \
			JABBERD_PIDDIR  USE_INET6

.if !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

PKG_GROUPS=             ${JABBERD_GROUP}
PKG_USERS=              ${JABBERD_USER}:${JABBERD_GROUP}::Jabberd\\ user

FILES_SUBST+=		JABBERD_USER="${JABBERD_USER}"
FILES_SUBST+=		JABBERD_GROUP="${JABBERD_GROUP}"
FILES_SUBST+=		JABBERD_SPOOLDIR="${JABBERD_SPOOLDIR}"
FILES_SUBST+=		JABBERD_PIDDIR="${JABBERD_PIDDIR}"

.for f in ${JABBERD_LOGDIR} ${JABBERD_SPOOLDIR} ${JABBERD_PIDDIR}
OWN_DIRS_PERMS+=	${f} ${JABBERD_USER} ${JABBERD_GROUP} 750
.endfor
.undef f

CONF_FILES=		${EGDIR}/jabber.xml ${PKG_SYSCONFDIR}/jabber.xml
SUPPORT_FILES=		${EGDIR}/platform-settings \
			${PKG_SYSCONFDIR}/platform-settings
post-extract:
	@${MV} ${WRKSRC}/jabber.xml ${WRKSRC}/jabber.xml.in

pre-configure:
	@${SED}	\
		-e "s|@LIBDIR@|${PREFIX}/lib/jabberd|g" \
		-e "s|@LOGDIR@|${JABBERD_LOGDIR}|g" \
		-e "s|@PIDDIR@|${JABBERD_PIDDIR}|g" \
		-e "s|@SPOOLDIR@|${JABBERD_SPOOLDIR}|g" \
		${WRKSRC}/jabber.xml.in > ${WRKSRC}/jabber.xml

do-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${LIBDIR} ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabber.xml ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/platform-settings ${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/jabberd/jabberd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/jsm/jsm.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/xdb_file/xdb_file.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/pthsock/pthsock_client.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dnsrv/dnsrv.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dialback/dialback.so ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/jabberd.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/lib/lib.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/lib/xmlparse.h ${INCDIR}

.include "../../devel/pth/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
