# $NetBSD: Makefile,v 1.14 2007/03/02 09:28:55 adrianp Exp $
#

DISTNAME=		tcptraceroute-1.4
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		http://michael.toren.net/code/tcptraceroute/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://michael.toren.net/code/tcptraceroute/
COMMENT=		Traceroute implementation using TCP packets

BUILD_TARGET=		tcptraceroute
BUILDLINK_API_DEPENDS.libnet10+=	libnet10>=1.0.2anb1

DOCDIR=			${PREFIX}/share/doc/tcptraceroute
BINMODE=		4711

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-build
SUBST_FILES.conf=	Makefile
SUBST_SED.conf=		-e "s|libnet-config|libnet10-config|g"
SUBST_MESSAGE.conf=	Fixing configuration script.

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptraceroute ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcptraceroute.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples.txt ${DOCDIR}

.include "../../devel/libnet10/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
