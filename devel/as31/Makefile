# $NetBSD: Makefile,v 1.3 2001/09/09 20:36:19 agc Exp $

DISTNAME=	asm.8051
PKGNAME=	as31-19900126
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.misc/volume10/ \
		ftp://sunsite.org.uk/usenet/comp.sources.misc/volume10/
EXTRACT_SUFX=	.Z

MAINTAINER=	bjh21@netbsd.org
COMMENT=	8031/8051 assembler

EXTRACT_CMD=	${DECOMPRESS_CMD} ${DOWNLOADED_DISTFILE} | \
		${SED} '1,/^.! \/bin\/sh/d' | ${SH}
WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
ALL_TARGET=	as31 man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/as31 ${PREFIX}/bin/as31
	${INSTALL_DATA} ${WRKSRC}/as31.man ${PREFIX}/man/man1/as31.1
	${INSTALL_DATA} ${WRKSRC}/as31.cat ${PREFIX}/man/cat1/as31.0

.include <../../mk/bsd.pkg.mk>
