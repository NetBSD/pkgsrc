# $NetBSD: Makefile,v 1.5 2004/10/03 00:18:00 tv Exp $
#

DISTNAME=		tcptraceroute-1.4
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://michael.toren.net/code/tcptraceroute/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://michael.toren.net/code/tcptraceroute/
COMMENT=		Traceroute implementation using TCP packets

USE_BUILDLINK3=		YES

ALL_TARGET=		tcptraceroute

DOCDIR=			${PREFIX}/share/doc/tcptraceroute
BINMODE=		4711

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptraceroute ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcptraceroute.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples.txt ${DOCDIR}

.include "../../devel/libnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
