# $NetBSD: Makefile,v 1.5 2003/07/17 21:29:30 grant Exp $

DISTNAME=	asm.8051
PKGNAME=	as31-19900126
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.misc/volume10/ \
		ftp://sunsite.org.uk/usenet/comp.sources.misc/volume10/
EXTRACT_SUFX=	.Z

MAINTAINER=	bjh21@NetBSD.org
COMMENT=	8031/8051 assembler

EXTRACT_CMD=	${DECOMPRESS_CMD} ${DOWNLOADED_DISTFILE} | \
		${SED} '1,/^.! \/bin\/sh/d' | ${SH}
MAKEFILE=	makefile
ALL_TARGET=	as31 man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/as31 ${PREFIX}/bin/as31
	${INSTALL_DATA} ${WRKSRC}/as31.man ${PREFIX}/man/man1/as31.1
	${INSTALL_DATA} ${WRKSRC}/as31.cat ${PREFIX}/man/cat1/as31.0

.include <../../mk/bsd.pkg.mk>
