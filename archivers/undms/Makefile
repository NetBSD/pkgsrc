# $NetBSD: Makefile,v 1.2 2000/01/15 01:37:00 tron Exp $

DISTNAME=	undms-1.3.c
PKGNAME=	undms-1.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	packages@netbsd.org

NO_WRKSUBDIR=
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} >${DISTNAME}

do-build:
	cd ${WRKSRC} && ${LINK.c} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
