# $NetBSD: Makefile,v 1.3 2003/07/17 21:21:46 grant Exp $
#

DISTNAME=	unzoo.c
PKGNAME=	unzoo-4.4
WRKSRC=		${WRKDIR}
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.math.rwth-aachen.de/pub/gap/gap4/util/
EXTRACT_SUFX=	# defined

MAINTAINER=	cjep@NetBSD.org
COMMENT=	Extract zoo archives

USE_BUILDLINK2=	YES

do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} &&	${CC} ${CFLAGS} -DSYS_IS_UNIX -DSYS_HAS_MKDIR -o unzoo unzoo.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unzoo ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
