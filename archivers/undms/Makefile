# $NetBSD: Makefile,v 1.15 2004/07/28 02:47:35 minskim Exp $

DISTNAME=	undms-1.3.c
PKGNAME=	undms-1.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/pub/aminet/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
EXTRACT_SUFX=	.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Converts .dms Amiga disk images to uncompressed .adf images

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
