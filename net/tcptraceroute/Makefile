# $NetBSD: Makefile,v 1.2 2003/12/28 06:33:26 kim Exp $
#

DISTNAME=		tcptraceroute-1.4
CATEGORIES=		net
MASTER_SITES=		http://michael.toren.net/code/tcptraceroute/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://michael.toren.net/code/tcptraceroute/
COMMENT=		Traceroute implementation using TCP packets

USE_BUILDLINK2=		YES

ALL_TARGET=		tcptraceroute

DOCDIR=			${PREFIX}/share/doc/tcptraceroute
BINMODE=		4711

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptraceroute ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcptraceroute.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples.txt ${DOCDIR}

.include "../../devel/libnet/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
