# $NetBSD: Makefile,v 1.4 2001/02/16 13:15:39 wiz Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Extracts .lzx archives from Amiga systems

EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} >${DISTNAME}
WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKSRC} && ${LINK.c} -o unlzx unlzx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unlzx ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
