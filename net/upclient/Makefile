# $NetBSD: Makefile,v 1.1.1.1 1999/04/06 20:09:59 hubertf Exp $
#

DISTNAME=	upclient-3.02
CATEGORIES=	net
MASTER_SITES=	http://uptime.hexon.cx/download/ \
		ftp://uptime.hexon.cx/pub/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://uptime.hexon.cx/

ALL_TARGET=	bsd
MESSAGE_FILE=	${WRKDIR}/.MESSAGE

post-extract:
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		${PKGDIR}/MESSAGE >${MESSAGE_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/upclient ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/upclient.conf ${PREFIX}/etc/upclient.conf.example
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		${FILESDIR}/upclient.sh >${PREFIX}/etc/rc.d/upclient.sh

.include "../../mk/bsd.pkg.mk"
