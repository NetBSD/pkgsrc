# $NetBSD: Makefile,v 1.7 2005/06/17 03:50:29 jlam Exp $
#

DISTNAME=		vpnc-0.3.2
CATEGORIES=		net security
MASTER_SITES=		http://www.unix-ag.uni-kl.de/~massar/vpnc/

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.unix-ag.uni-kl.de/~massar/vpnc/
COMMENT=		Client for Cisco3000 VPN Concentrator

USE_TOOLS+=		gmake
BUILD_TARGET=		vpnc
INSTALLATION_DIRS=	bin man/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vpnc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-connect ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-disconnect ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vpnc.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vpnc
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/vpnc
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vpnc
	${INSTALL_MAN} ${WRKSRC}/vpnc.conf ${PREFIX}/share/examples/vpnc

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
