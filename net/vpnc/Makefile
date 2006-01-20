# $NetBSD: Makefile,v 1.10 2006/01/20 11:29:52 hubertf Exp $
#

DISTNAME=		vpnc-0.3.3
CATEGORIES=		net security
MASTER_SITES=		http://www.unix-ag.uni-kl.de/~massar/vpnc/

MAINTAINER=		hubertf@NetBSD.org,j+pkgsrc@salmi.ch
HOMEPAGE=		http://www.unix-ag.uni-kl.de/~massar/vpnc/
COMMENT=		Client for Cisco3000 VPN Concentrator

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake
BUILD_TARGET=		vpnc
INSTALLATION_DIRS=	bin man/man8

USE_PKGINSTALL=		yes
EGDIR=                  ${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/vpnc.conf ${PKG_SYSCONFDIR}/vpnc.conf
CONF_FILES+=		${EGDIR}/vpnc-script ${PKG_SYSCONFDIR}/vpnc-script
CONF_FILES_MODE=	755	# vpn-script must be executable!

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vpnc
	${INSTALL_DATA_DIR} ${EGDIR}
	:
	${INSTALL_PROGRAM} ${WRKSRC}/vpnc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-disconnect ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vpnc.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/vpnc
	${INSTALL_MAN} ${WRKSRC}/vpnc.conf ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script ${EGDIR}

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
