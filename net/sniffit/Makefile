# $NetBSD: Makefile,v 1.40 2024/05/06 08:40:31 jperkin Exp $
#

DISTNAME=		sniffit.0.3.5
PKGNAME=		sniffit-0.3.5
PKGREVISION=		7
CATEGORIES=		net security
MASTER_SITES=		http://reptile.rug.ac.be/~coder/sniffit/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://reptile.rug.ac.be/~coder/sniffit/sniffit.html
COMMENT=		Packet sniffer program

BROKEN_ON_PLATFORM=	${LP64PLATFORMS}	# severe LP64 loss

GNU_CONFIGURE=		YES
BUILD_TARGET=
INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin

CONFIGURE_ENV+=		NCURSES_LOCATION=${BUILDLINK_DIR}/include/ncurses.h

post-extract:
	${RM} -rf ${WRKSRC}/libpcap-0.3
	${RM} -f ${WRKSRC}/pcap.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${DESTDIR}${PREFIX}/sbin/sniffit
	${INSTALL_MAN}     ${WRKSRC}/sniffit.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN}     ${WRKSRC}/sniffit.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
