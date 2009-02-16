# $NetBSD: Makefile,v 1.10 2009/02/16 19:12:00 joerg Exp $
#

DISTNAME=		service-config-0.51
CATEGORIES=		sysutils
MASTER_SITES=		http://www.superscript.com/service-config/

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://www.superscript.com/service-config/intro.html
COMMENT=		Utility to create and configure svscan service directories

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

# Possibly inherited DJB-style distribution terms
DJB_RESTRICTED=		YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rules-config ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/service-config ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ipc-config ipcx-config \
	    svscan-config tcp-config tcpx-config ${DESTDIR}${PREFIX}/bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
