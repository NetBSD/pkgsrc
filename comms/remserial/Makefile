# $NetBSD: Makefile,v 1.3 2024/05/20 13:03:49 gdt Exp $

DISTNAME=	remserial-1.4
CATEGORIES=	comms
MASTER_SITES=	http://lpccomp.bc.ca/remserial/ # https has bad or old ssl protocol

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpccomp.bc.ca/remserial/
COMMENT=	Serial port over LAN through TCP/IP
LICENSE=	gnu-gpl-v2
INSTALLATION_DIRS=      bin share/doc/remserial

LDFLAGS.SunOS+=	-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/remserial ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.txt \
	    ${DESTDIR}${PREFIX}/share/doc/remserial

.include "../../mk/bsd.pkg.mk"
