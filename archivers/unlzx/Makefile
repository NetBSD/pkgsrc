# $NetBSD: Makefile,v 1.1.1.1 1999/05/22 21:11:07 tv Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.germany.aminet.org/pub/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	packages@netbsd.org

NO_WRKSUBDIR=
EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} >${DISTNAME}

do-build:
	cd ${WRKSRC} && ${LINK.c} -o unlzx unlzx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unlzx ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
