# $NetBSD: Makefile,v 1.16 2023/10/14 16:52:54 schmonz Exp $
#

DISTNAME=		service-config-0.51
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://web.archive.org/web/20090302170825/http://www.superscript.com/service-config/intro.html
COMMENT=		Utility to create and configure svscan service directories
LICENSE=		djb-nonlicense

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools

SUBST_CLASSES+=		djberrno

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rules-config ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/service-config ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ipc-config ipcx-config \
	    svscan-config tcp-config tcpx-config ${DESTDIR}${PREFIX}/bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
