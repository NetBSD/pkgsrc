# $NetBSD: Makefile,v 1.9 2001/06/20 14:30:47 nra Exp $
#

DISTNAME=	upclient-4.2.1.23
CATEGORIES=	net
MASTER_SITES=	http://uptimes.atomicvoid.net/files/ \
		http://www.uptimes.net/download/ \
		ftp://ftp.uptimes.net/pub/uptimes/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.uptimes.net/
COMMENT=	Keeps track of your server uptime, and compares it to other hosts

ALL_TARGET=	bsd

post-patch:
	${MV} ${WRKSRC}/scripts/upchk ${WRKSRC}/scripts/upchk.bak
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		>${WRKSRC}/scripts/upchk <${WRKSRC}/scripts/upchk.bak

do-build:
	cd ${WRKSRC}/src && ${MAKE} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upclient ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/HISTORY ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/conf/upclient.conf ${PREFIX}/etc
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@INSTALL@|${INSTALL}|g' \
		-e 's|@SU@|${SU}|g' \
		${FILESDIR}/upclient.sh >${PREFIX}/etc/rc.d/upclient
	${CHMOD} +x ${PREFIX}/etc/rc.d/upclient

.include "../../mk/bsd.pkg.mk"
