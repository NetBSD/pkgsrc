# $NetBSD: Makefile,v 1.5 2001/07/16 10:29:51 jlam Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Extracts .lzx archives from Amiga systems

USE_BUILDLINK_ONLY=	# defined
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} >${DISTNAME}
WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKSRC} && ${LINK.c} -o unlzx unlzx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unlzx ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
