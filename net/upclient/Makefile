# $NetBSD: Makefile,v 1.15 2004/01/19 00:02:18 jklos Exp $
#

DISTNAME=	upclient-4.2.1.23
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://uptimes.atomicvoid.net/files/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://uptimes.hostingwired.com/
COMMENT=	Keeps track of your server uptime, and compares it to other hosts

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES

ALL_TARGET=	bsd

EGDIR=		${PREFIX}/share/examples/upclient
CONF_FILES=	${EGDIR}/upclient.conf ${PKG_SYSCONFDIR}/upclient.conf
CFLAGS+=	-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"

RCD_SCRIPTS=	upclient

BUILD_DIRS=	${WRKSRC}/src

pre-configure:
	${MV} ${WRKSRC}/scripts/upchk ${WRKSRC}/scripts/upchk.bak
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		>${WRKSRC}/scripts/upchk <${WRKSRC}/scripts/upchk.bak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upclient ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/HISTORY ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/upclient
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/upclient
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/upclient.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
