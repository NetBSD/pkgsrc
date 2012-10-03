# $NetBSD: Makefile,v 1.35 2012/10/03 00:02:39 asau Exp $
#

DISTNAME=		jabber-1.4.2
PKGNAME=		jabberd-1.4.2
PKGREVISION=		9
CATEGORIES=		chat
MASTER_SITES=		http://download.jabberd.org/jabberd14/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jabberstudio.org/projects/jabberd
COMMENT=		Instant messaging server

CONFLICTS=		jabberd2-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# A self-made configure script, and GNU ones in subdirectories.
HAS_CONFIGURE=			yes
OVERRIDE_GNU_CONFIG_SCRIPTS=	yes
USE_TOOLS+=			gmake

CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		prefix=${PREFIX}
CONFIGURE_ENV+=		SSLBASE=${SSLBASE}

RCD_SCRIPTS=		jabberd
PKG_SYSCONFSUBDIR=	jabberd

EGDIR=			${PREFIX}/share/examples/jabberd
LIBDIR=			${PREFIX}/lib/jabberd
INCDIR=			${PREFIX}/include/jabberd

.include "options.mk"

# some systems don't have u_intN_t
CPPFLAGS+=		-Du_int8_t=uint8_t

BUILD_DEFS+=		JABBERD_LOGDIR	JABBERD_SPOOLDIR \
			JABBERD_PIDDIR

PKG_GROUPS=             ${JABBERD_GROUP}
PKG_USERS=              ${JABBERD_USER}:${JABBERD_GROUP}

PKG_USERS_VARS+=	JABBERD_USER
PKG_GROUPS_VARS+=	JABBERD_GROUP

FILES_SUBST+=		JABBERD_USER=${JABBERD_USER:Q}
FILES_SUBST+=		JABBERD_GROUP=${JABBERD_GROUP:Q}
FILES_SUBST+=		JABBERD_SPOOLDIR=${JABBERD_SPOOLDIR:Q}
FILES_SUBST+=		JABBERD_PIDDIR=${JABBERD_PIDDIR:Q}

.for f in ${JABBERD_LOGDIR} ${JABBERD_SPOOLDIR} ${JABBERD_PIDDIR}
OWN_DIRS_PERMS+=	${f} ${JABBERD_USER} ${JABBERD_GROUP} 750
.endfor

CONF_FILES=		${EGDIR}/jabber.xml ${PKG_SYSCONFDIR}/jabber.xml
CONF_FILES+=		${EGDIR}/platform-settings \
			${PKG_SYSCONFDIR}/platform-settings

INSTALLATION_DIRS=	sbin

post-extract:
	@${MV} ${WRKSRC}/jabber.xml ${WRKSRC}/jabber.xml.in

pre-configure:
	@${SED}	\
		-e "s|@LIBDIR@|${PREFIX}/lib/jabberd|g" \
		-e "s|@LOGDIR@|${JABBERD_LOGDIR}|g" \
		-e "s|@PIDDIR@|${JABBERD_PIDDIR}|g" \
		-e "s|@SPOOLDIR@|${JABBERD_SPOOLDIR}|g" \
		${WRKSRC}/jabber.xml.in > ${WRKSRC}/jabber.xml
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/jabberd/pth-1.4.0
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/jabberd/pth-1.4.0

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR} ${DESTDIR}${LIBDIR} \
		${DESTDIR}${INCDIR} ${DESTDIR}${INCDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/jabber.xml ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/platform-settings ${DESTDIR}${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/jabberd/jabberd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/jsm/jsm.so ${DESTDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/xdb_file/xdb_file.so ${DESTDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/pthsock/pthsock_client.so ${DESTDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dnsrv/dnsrv.so ${DESTDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dialback/dialback.so ${DESTDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/jabberd.h ${DESTDIR}${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/jabberd/lib/lib.h ${DESTDIR}${INCDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/jabberd/lib/xmlparse.h ${DESTDIR}${INCDIR}/lib

#.include "../../devel/pth/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
