# $NetBSD: Makefile,v 1.8 2002/08/25 21:49:24 jlam Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.gz

MAINTAINER=	packages@netbsd.org
COMMENT=	Extracts .lzx archives from Amiga systems

USE_BUILDLINK2=	# defined
WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKSRC} && ${BUILDLINK_CC} ${CFLAGS} -o unlzx unlzx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unlzx ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
