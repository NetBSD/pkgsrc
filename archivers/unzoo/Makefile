# $NetBSD: Makefile,v 1.8 2005/09/28 19:45:45 rillig Exp $
#

DISTNAME=	unzoo.c
PKGNAME=	unzoo-4.4
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.math.rwth-aachen.de/pub/gap/gap4/util/
EXTRACT_SUFX=	# empty

MAINTAINER=	cjep@NetBSD.org
COMMENT=	Extract zoo archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} &&	${CC} ${CFLAGS} -DSYS_IS_UNIX -DSYS_HAS_MKDIR -o unzoo unzoo.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unzoo ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
