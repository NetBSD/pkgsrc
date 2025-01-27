# $NetBSD: Makefile,v 1.25 2025/01/27 19:12:39 rillig Exp $

DISTNAME=	undms-1.3.c
PKGNAME=	undms-1.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.fau.de/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Converts .dms Amiga disk images to uncompressed .adf images

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
