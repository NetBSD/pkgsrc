# $NetBSD: Makefile,v 1.14 2005/12/05 20:49:51 rillig Exp $

DISTNAME=	netio123
PKGNAME=	netio-1.23
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.leo.org/pub/historic/comp/os/os2/leo/systools/
EXTRACT_SUFX=	.zip

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
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/netio
	${INSTALL_DATA} ${WRKSRC}/netio.doc ${PREFIX}/share/doc/netio

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
