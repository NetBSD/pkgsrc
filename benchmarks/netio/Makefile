# $NetBSD: Makefile,v 1.1.1.1 2001/04/17 12:25:33 tron Exp $

DISTNAME=	netio113
PKGNAME=	netio-1.13
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.leo.org/pub/comp/os/os2/leo/systools/
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@netbsd.org
COMMENT=	Network benchmark for DOS, OS/2 2.x, Windows NT/2000 and Unix

ALL_TARGET=	pkgsrc
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/netio
	${INSTALL_DATA} ${WRKSRC}/netio.doc ${PREFIX}/share/doc/netio

.include "../../mk/bsd.pkg.mk"
