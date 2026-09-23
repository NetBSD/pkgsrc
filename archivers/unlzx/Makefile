# $NetBSD: Makefile,v 1.28 2026/09/23 06:07:39 wiz Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.1
CATEGORIES=	archivers
MASTER_SITES=	https://ftp.fau.de/aminet/misc/unix/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extracts .lzx archives from Amiga systems

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

CFLAGS+=	-Wno-implicit-function-declaration

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o unlzx unlzx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unlzx ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
