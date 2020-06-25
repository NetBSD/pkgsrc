# $NetBSD: Makefile,v 1.14 2020/06/25 05:42:39 schmonz Exp $
#

DISTNAME=		service-config-0.51
CATEGORIES=		sysutils
MASTER_SITES=		http://www.superscript.com/service-config/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.superscript.com/service-config/intro.html
COMMENT=		Utility to create and configure svscan service directories

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

# Possibly inherited DJB-style distribution terms
DJB_RESTRICTED=		YES

SUBST_CLASSES+=		djberrno

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rules-config ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/service-config ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ipc-config ipcx-config \
	    svscan-config tcp-config tcpx-config ${DESTDIR}${PREFIX}/bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
