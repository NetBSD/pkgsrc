# $NetBSD: Makefile,v 1.4 2014/02/09 00:44:36 wiedi Exp $
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

NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin share/sbd

OWN_DIRS+=	${PKG_SYSCONFDIR}/sbd

LDFLAGS.SunOS+=	-lsocket -lnsl

do-build:
	cd ${WRKSRC} && \
	${CXX} -DPKG_SYSCONFDIR=\""${PKG_SYSCONFDIR}/sbd\"" -Wall -O2 -o sbdd ssocket.cpp sha1.cpp utils.cpp sbdd.cpp ${LDFLAGS}; \
	${CXX} -DPKG_SYSCONFDIR=\""${PKG_SYSCONFDIR}/sbd\"" -Wall -O2 -o sbd csocket.cpp sha1.cpp utils.cpp sbd.cpp ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbdd ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sbd ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/PROTOCOL ${DESTDIR}${PREFIX}/share/sbd/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/sbd/
	${INSTALL_DATA} ${WRKSRC}/athkey.bits ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/deckey.bits ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/enckey.bits ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
