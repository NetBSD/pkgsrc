# $NetBSD: Makefile,v 1.20 2005/06/16 06:57:41 jlam Exp $
#

DISTNAME=		bitlbee-0.91
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://get.bitlbee.org/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.bitlbee.org/
COMMENT=		IRC to other chat networks gateway

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--config=${STATEDIR}
CONFIGURE_ARGS+=	--flood=1
CONFIGURE_ARGS+=	--ssl=openssl

PKG_SYSCONFSUBDIR=	bitlbee
CONF_FILES=		${DATADIR}/motd.txt ${PKG_SYSCONFDIR}/motd.txt
CONF_FILES+=		${EGDIR}/bitlbee.conf ${PKG_SYSCONFDIR}/bitlbee.conf

EGDIR=			${PREFIX}/share/examples/bitlbee
DATADIR=		${PREFIX}/share/bitlbee
DOCDIR=			${PREFIX}/share/doc/bitlbee
STATEDIR=		${VARBASE}/db/bitlbee

OWN_DIRS_PERMS=		${STATEDIR} bitlbee nobody 700

PKG_USERS=		bitlbee:nobody::Bitlbee\\ user:${VARBASE}/db/bitlbee

INSTALLATION_DIRS=	man/man8 sbin

do-install:
	${INSTALL_DATA_DIR} ${DATADIR} ${DOCDIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/bitlbee.conf ${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bitlbee ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/help.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/motd.txt ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/bitlbee.8 ${PREFIX}/man/man8
.for f in AUTHORS FAQ README TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCDIR}
.endfor
.undef f

PKG_OPTIONS_VAR=	PKG_OPTIONS.bitlbee
PKG_SUPPORTED_OPTIONS=	inet6
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--ipv6=1
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
