# $NetBSD: Makefile,v 1.15 2004/03/23 04:40:59 jlam Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Extracts .lzx archives from Amiga systems

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o unlzx unlzx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unlzx ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
