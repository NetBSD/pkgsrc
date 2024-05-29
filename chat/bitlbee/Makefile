# $NetBSD: Makefile,v 1.98 2024/05/29 16:31:28 adam Exp $

DISTNAME=		bitlbee-3.6
PKGREVISION=		16
CATEGORIES=		chat
MASTER_SITES=		https://get.bitlbee.org/src/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		https://www.bitlbee.org/
COMMENT=		IRC to other chat networks gateway
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
TOOL_DEPENDS+=		w3m-[0-9]*:../../www/w3m

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

REPLACE_PYTHON+=	configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--config=${STATEDIR}
CONFIGURE_ARGS+=	--pidfile=${VARBASE}/run/bitlbee/pid
CONFIGURE_ARGS+=	--ipcsocket=${VARBASE}/run/bitlbee/sock
CONFIGURE_ARGS+=	--flood=0
CONFIGURE_ARGS+=	--ssl=gnutls
CONFIGURE_ARGS.SunOS+=	--pie=0

PKG_SYSCONFSUBDIR=	bitlbee
CONF_FILES=		${DATADIR}/motd.txt ${PKG_SYSCONFDIR}/motd.txt
CONF_FILES+=		${EGDIR}/bitlbee.conf ${PKG_SYSCONFDIR}/bitlbee.conf

BUILD_DEFS+=		VARBASE BITLBEE_USER BITLBEE_GROUP
FILES_SUBST+=		BITLBEE_USER=${BITLBEE_USER} BITLBEE_GROUP=${BITLBEE_GROUP}

EGDIR=			${PREFIX}/share/examples/bitlbee
DATADIR=		${PREFIX}/share/bitlbee
DOCDIR=			${PREFIX}/share/doc/bitlbee
STATEDIR=		${VARBASE}/db/bitlbee

.include "../../mk/bsd.prefs.mk"

BITLBEE_USER?=		bitlbee
BITLBEE_GROUP?=		nobody

OWN_DIRS_PERMS=		${STATEDIR} ${BITLBEE_USER} ${BITLBEE_GROUP} 700
OWN_DIRS_PERMS+=	${VARBASE}/run/bitlbee ${BITLBEE_USER} ${BITLBEE_GROUP} 700

PKG_GROUPS=		${BITLBEE_GROUP}
PKG_USERS=		${BITLBEE_USER}:${BITLBEE_GROUP}
PKG_HOME.bitlbee=	${VARBASE}/db/bitlbee

INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin
INSTALLATION_DIRS+=	lib/pkgconfig include/bitlbee

CPPFLAGS.SunOS+=	-Du_int16_t=uint16_t

post-build:
	cd ${WRKSRC}/doc/user-guide && \
		${BUILD_MAKE_CMD} user-guide.txt user-guide.html

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
	${INSTALL_DATA} ${WRKSRC}/bitlbee.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/*.h ${DESTDIR}${PREFIX}/include/bitlbee
	${INSTALL_DATA} ${WRKSRC}/lib/*.h ${DESTDIR}${PREFIX}/include/bitlbee
	${INSTALL_DATA} ${WRKSRC}/protocols/*.h ${DESTDIR}${PREFIX}/include/bitlbee

RCD_SCRIPTS=		bitlbee
RCD_SCRIPT_SRC.bitlbee=	${FILESDIR}/bitlbee.sh

# see https://savannah.gnu.org/support/index.php?107660
#BUILDLINK_ABI_DEPENDS.gnutls+=	gnutls<2.12.0

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
