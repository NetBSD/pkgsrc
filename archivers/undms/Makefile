# $NetBSD: Makefile,v 1.6.2.2 2002/06/21 23:04:52 jlam Exp $

DISTNAME=	undms-1.3.c
PKGNAME=	undms-1.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Converts .dms Amiga disk images to uncompressed .adf images

USE_BUILDLINK2=	# defined
WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKSRC} && ${BUILDLINK_CC} ${CFLAGS} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
