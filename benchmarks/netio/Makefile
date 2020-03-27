# $NetBSD: Makefile,v 1.22 2020/03/27 16:02:04 jdolecek Exp $

DISTNAME=	netio133
PKGNAME=	netio-1.33
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.ars.de/
EXTRACT_SUFX=	.zip

HOMEPAGE=	https://web.ars.de/netio/
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Network benchmark for OS/2 2.x, Windows NT/2000 and Unix
LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}
NETIO_CFLAGS+=	-DUNIX ${PTHREAD_CFLAGS} ${CFLAGS}
MAKE_FLAGS+=	CC=${CC:Q} CFLAGS="${NETIO_CFLAGS}" \
		LFLAGS="${PTHREAD_LDFLAGS} ${LDFLAGS}" \
		LIBS="${PTHREAD_LIBS} ${LIBS}" O=.o OUT=-o X=

.include "../../mk/bsd.prefs.mk"

LIBS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin

post-build:
	${RUN}cd ${WRKSRC} && \
	${BUILD_MAKE_CMD} O=.6o X=6 CFLAGS="${NETIO_CFLAGS} -DUSE_IPV6" \
		${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/netio6 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/netio
	${INSTALL_DATA} ${WRKSRC}/netio.doc \
		${DESTDIR}${PREFIX}/share/doc/netio/netio.txt

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
