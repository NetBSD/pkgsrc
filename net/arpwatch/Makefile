# $NetBSD: Makefile,v 1.35 2013/02/06 19:30:55 jperkin Exp $
#

DISTNAME=	arpwatch-2.1a15
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Monitor ARP activity on a network, maintaining a database

RCD_SCRIPTS=	arpwatch

GNU_CONFIGURE=	yes

CFLAGS.Darwin+=	-DBIND_8_COMPAT
LIBS+=		${BUILDLINK_LDADD.libpcap}

MAKE_ENV+=	VARBASE=${VARBASE:Q}
PLIST_SUBST+=	VARBASE=${VARBASE:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	arpsnmp.8 arpwatch.8
SUBST_SED.paths=	-e 's,/usr/operator/arpwatch,${VARBASE}/db/arpwatch,g'

OWN_DIRS=	${VARBASE:Q}/db/arpwatch

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/examples/arpwatch share/arpwatch

CONF_FILES+=	/dev/null ${VARBASE}/db/arpwatch/arp.dat

pre-patch:
	f=arpwatch.h;							\
	${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f-prepatch;			\
	${SED} -e '/Header/s|\$$||g' ${WRKSRC}/$$f-prepatch > ${WRKSRC}/$$f

post-install:
	${INSTALL_MAN} ${WRKSRC}/arpwatch.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/arpsnmp.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/ethercodes.dat ${DESTDIR}${PREFIX}/share/arpwatch
	${INSTALL_DATA} ${WRKSRC}/bihourly.sh ${DESTDIR}${PREFIX}/share/examples/arpwatch/bihourly.sh
	${INSTALL_DATA} ${WRKSRC}/arpfetch ${DESTDIR}${PREFIX}/share/examples/arpwatch/arpfetch

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
