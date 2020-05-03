# $NetBSD: Makefile,v 1.2 2020/05/03 18:14:01 wiedi Exp $

DISTNAME=	remserial-1.4
CATEGORIES=	comms
MASTER_SITES=	http://lpccomp.bc.ca/remserial/

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
