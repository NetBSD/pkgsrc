# $NetBSD: Makefile,v 1.4 2001/06/04 23:16:57 jtb Exp $

DISTNAME=	netio114
PKGNAME=	netio-1.14
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/os2/leo/systools/
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@netbsd.org
COMMENT=	Network benchmark for DOS, OS/2 2.x, Windows NT/2000 and Unix

LICENSE=	non-commercial

ALL_TARGET=	pkgsrc
WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
MAKE_ENV+=	LIBS="-lsocket -lnsl"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/netio
	${INSTALL_DATA} ${WRKSRC}/netio.doc ${PREFIX}/share/doc/netio

.include "../../mk/bsd.pkg.mk"
