# $NetBSD: Makefile,v 1.9 2004/01/20 12:08:12 agc Exp $

DISTNAME=	netio114
PKGNAME=	netio-1.14
PKGREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/os2/leo/systools/
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@NetBSD.org
COMMENT=	Network benchmark for DOS, OS/2 2.x, Windows NT/2000 and Unix

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}
MAKE_FLAGS+=	CC="${CC}" CFLAGS="-DUNIX ${CFLAGS}" LFLAGS="${LDFLAGS}" \
		LIBS="${LIBS}" O=.o OUT=-o X=

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
LIBS+=		-lsocket -lnsl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/netio
	${INSTALL_DATA} ${WRKSRC}/netio.doc ${PREFIX}/share/doc/netio

.include "../../mk/bsd.pkg.mk"
