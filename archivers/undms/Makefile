# $NetBSD: Makefile,v 1.13 2004/03/11 18:03:50 xtraeme Exp $

DISTNAME=	undms-1.3.c
PKGNAME=	undms-1.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Converts .dms Amiga disk images to uncompressed .adf images

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	# defined

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
