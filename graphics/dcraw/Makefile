# $NetBSD: Makefile,v 1.7 2004/10/03 00:14:49 tv Exp $
#

DISTNAME=	dcraw
PKGNAME=	dcraw-1.206
PKGREVISION=	1
CATEGORIES=	graphics
# distfile changes frequently, use copy on ftp.NetBSD.org
#MASTER_SITES=	http://www.cybercom.net/~dcoffin/dcraw/
MASTER_SITES=	http://www.cybercom.net/~dcoffin/dcraw/
DISTFILES=	dcraw.c dcraw.1
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cybercom.net/~dcoffin/dcraw/
COMMENT=	Raw digital camera decoder

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes
LIBS+=		-lm -ljpeg

do-extract:
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC})

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} dcraw.c -o dcraw ${LDFLAGS} ${LIBS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dcraw ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dcraw.1 ${PREFIX}/man/man1

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
