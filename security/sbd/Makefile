# $NetBSD: Makefile,v 1.1.1.1 2007/05/10 18:18:16 agc Exp $
#

DISTNAME=	sbd-0.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sbd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sbd/
COMMENT=	HMAC & one-time pad-based remote login program

WRKSRC=		${WRKDIR}/sbd

USE_LANGUAGES+=	c c++

EGDIR=		${PREFIX}/share/sbd
CONF_FILES=	${EGDIR}/deckey.bits ${PKG_SYSCONFDIR}/sbd/deckey.bits
CONF_FILES+=	${EGDIR}/enckey.bits ${PKG_SYSCONFDIR}/sbd/enckey.bits
CONF_FILES+=	${EGDIR}/athkey.bits ${PKG_SYSCONFDIR}/sbd/athkey.bits

do-configure:

do-build:
	cd ${WRKSRC} && \
	${CXX} -DPKG_SYSCONFDIR=\""${PKG_SYSCONFDIR}/sbd\"" -Wall -O2 -o sbdd ssocket.cpp sha1.cpp utils.cpp sbdd.cpp; \
	${CXX} -DPKG_SYSCONFDIR=\""${PKG_SYSCONFDIR}/sbd\"" -Wall -O2 -o sbd csocket.cpp sha1.cpp utils.cpp sbd.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbdd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sbd ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/sbd
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/sbd
	${INSTALL_DATA} ${WRKSRC}/PROTOCOL ${PREFIX}/share/sbd/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/sbd/
	${INSTALL_DATA} ${WRKSRC}/athkey.bits ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/deckey.bits ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/enckey.bits ${EGDIR}

.include "../../mk/bsd.pkg.mk"
