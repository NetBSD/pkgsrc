# $NetBSD: Makefile,v 1.24 2014/10/09 14:05:54 wiz Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/misc/unix/

EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extracts .lzx archives from Amiga systems

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o unlzx unlzx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unlzx ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
