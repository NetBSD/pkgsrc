# $NetBSD: Makefile,v 1.1 2020/02/15 02:26:58 manu Exp $

DISTNAME=	remserial-1.4
CATEGORIES=	comms
MASTER_SITES=	http://lpccomp.bc.ca/remserial/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpccomp.bc.ca/remserial/
COMMENT=	Serial port over LAN through TCP/IP
LICENSE=	gnu-gpl-v2
INSTALLATION_DIRS=      bin share/doc/remserial

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/remserial ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.txt \
	    ${DESTDIR}${PREFIX}/share/doc/remserial

.include "../../mk/bsd.pkg.mk"
