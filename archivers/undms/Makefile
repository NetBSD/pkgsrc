# $NetBSD: Makefile,v 1.27 2026/09/23 20:33:50 rhialto Exp $

DISTNAME=	undms-1.3.c
PKGNAME=	undms-1.3
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://ftp.fau.de/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Converts .dms Amiga disk images to uncompressed .adf images

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
