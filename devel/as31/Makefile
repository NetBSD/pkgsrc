# $NetBSD: Makefile,v 1.11 2006/01/21 18:57:40 jlam Exp $

DISTNAME=	asm.8051
PKGNAME=	as31-19900126
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.misc/volume10/ \
		ftp://sunsite.org.uk/usenet/comp.sources.misc/volume10/
EXTRACT_SUFX=	.Z

MAINTAINER=	bjh21@NetBSD.org
COMMENT=	8031/8051 assembler

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | \
		${SED} '1,/^.! \/bin\/sh/d' | ${SH}
MAKEFILE=	makefile
BUILD_TARGET=	as31

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/as31 ${PREFIX}/bin/as31
	${INSTALL_DATA} ${WRKSRC}/as31.man ${PREFIX}/man/man1/as31.1

.include "../../mk/bsd.pkg.mk"
