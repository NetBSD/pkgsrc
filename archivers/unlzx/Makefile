# $NetBSD: Makefile,v 1.12 2004/01/20 12:07:07 agc Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.gz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Extracts .lzx archives from Amiga systems

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	# defined

do-build:
	cd ${WRKSRC} && ${BUILDLINK_CC} ${CFLAGS} -o unlzx unlzx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unlzx ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
