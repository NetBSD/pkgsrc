# $NetBSD: Makefile,v 1.19 2012/09/11 22:37:13 asau Exp $

DISTNAME=	netio126
PKGNAME=	netio-1.26
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.ars.de/ars/ars.nsf/f24a6a0b94c22d82862566960071bf5a/aa577bc4be573b05c125706d004c75b5/\$$FILE/
EXTRACT_SUFX=	.zip

HOMEPAGE=	http://www.ars.de/ars/ars.nsf/docs/netio
MAINTAINER=	tron@NetBSD.org
COMMENT=	Network benchmark for OS/2 2.x, Windows NT/2000 and Unix
LICENSE=	no-commercial-use

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
MAKE_FLAGS+=	CC=${CC:Q} CFLAGS="-DUNIX ${PTHREAD_CFLAGS} ${CFLAGS}" \
		LFLAGS="${PTHREAD_LDFLAGS} ${LDFLAGS}" \
		LIBS="${PTHREAD_LIBS} ${LIBS}" O=.o OUT=-o X=

.include "../../mk/bsd.prefs.mk"

LIBS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/netio
	${INSTALL_DATA} ${WRKSRC}/netio.doc \
		${DESTDIR}${PREFIX}/share/doc/netio/netio.txt

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
