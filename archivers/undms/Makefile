# $NetBSD: Makefile,v 1.11 2004/01/20 12:07:07 agc Exp $

DISTNAME=	undms-1.3.c
PKGNAME=	undms-1.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Converts .dms Amiga disk images to uncompressed .adf images

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	# defined

do-build:
	cd ${WRKSRC} && ${BUILDLINK_CC} ${CFLAGS} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
