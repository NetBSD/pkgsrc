# $NetBSD: Makefile,v 1.22 2005/03/17 11:01:44 markd Exp $
#

DISTNAME=	arpwatch-2.1a11
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Monitor ARP activity on a network, maintaining a database

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

LIBS+=		${BUILDLINK_LDADD.libpcap}

MAKE_ENV+=	VARBASE=${VARBASE}
PLIST_SUBST+=	VARBASE=${VARBASE}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	arpsnmp.8 arpwatch.8
SUBST_SED.paths=	-e 's,/usr/operator/arpwatch,${VARBASE}/db/arpwatch,g'

pre-patch:
	f=arpwatch.h;							\
	${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f-prepatch;			\
	${SED} -e '/Header/s|\$$||g' ${WRKSRC}/$$f-prepatch > ${WRKSRC}/$$f

post-install:
	${INSTALL_MAN} ${WRKSRC}/arpwatch.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/arpsnmp.8 ${PREFIX}/man/man8
	@${INSTALL_DATA_DIR} ${VARBASE}/db/arpwatch
	${TOUCH} ${VARBASE}/db/arpwatch/arp.dat
	${INSTALL_DATA} ${WRKSRC}/ethercodes.dat ${PREFIX}/etc

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
