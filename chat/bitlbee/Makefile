# $NetBSD: Makefile,v 1.62 2012/10/03 00:02:34 asau Exp $
#

DISTNAME=		bitlbee-3.0.3
PKGREVISION=		6
CATEGORIES=		chat
MASTER_SITES=		http://get.bitlbee.org/src/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.bitlbee.org/
COMMENT=		IRC to other chat networks gateway
LICENSE=		gnu-gpl-v2

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--config=${STATEDIR}
CONFIGURE_ARGS+=	--pidfile=${VARBASE}/run/bitlbee/pid
CONFIGURE_ARGS+=	--ipcsocket=${VARBASE}/run/bitlbee/sock
CONFIGURE_ARGS+=	--flood=0
CONFIGURE_ARGS+=	--ssl=gnutls

PKG_SYSCONFSUBDIR=	bitlbee
CONF_FILES=		${DATADIR}/motd.txt ${PKG_SYSCONFDIR}/motd.txt
CONF_FILES+=		${EGDIR}/bitlbee.conf ${PKG_SYSCONFDIR}/bitlbee.conf
OWN_DIRS+=		${VARBASE}/run/bitlbee

BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/bitlbee
DATADIR=		${PREFIX}/share/bitlbee
DOCDIR=			${PREFIX}/share/doc/bitlbee
STATEDIR=		${VARBASE}/db/bitlbee

OWN_DIRS_PERMS=		${STATEDIR} bitlbee nobody 700

PKG_GROUPS=		nobody
PKG_USERS=		bitlbee:nobody
PKG_HOME.bitlbee=	${VARBASE}/db/bitlbee

INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/bitlbee.conf ${DESTDIR}${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bitlbee ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/user-guide/help.txt ${DESTDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/motd.txt ${DESTDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/bitlbee.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/doc/bitlbee.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
.for f in AUTHORS FAQ README CREDITS user-guide/user-guide.txt user-guide/user-guide.html
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${DOCDIR}
.endfor

PKG_OPTIONS_VAR=	PKG_OPTIONS.bitlbee
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--ipv6=1
.else
CONFIGURE_ARGS+=	--ipv6=0
.endif

RCD_SCRIPTS=		bitlbee
RCD_SCRIPT_SRC.bitlbee=	${FILESDIR}/bitlbee.sh

# see https://savannah.gnu.org/support/index.php?107660
#BUILDLINK_ABI_DEPENDS.gnutls+= gnutls<2.12.0

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
