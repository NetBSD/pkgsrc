# $NetBSD: Makefile,v 1.6 2002/02/25 04:47:21 jlam Exp $

DISTNAME=	undms-1.3.c
PKGNAME=	undms-1.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	Converts .dms Amiga disk images to uncompressed .adf images

USE_BUILDLINK_ONLY=	# defined
WRKSRC=			${WRKDIR}

do-build:
	cd ${WRKSRC} && ${LINK.c} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
