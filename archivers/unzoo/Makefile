# $NetBSD: Makefile,v 1.10 2006/06/18 07:04:16 rillig Exp $
#

DISTNAME=	unzoo.c
PKGNAME=	unzoo-4.4
CATEGORIES=	archivers
MASTER_SITES=	# no dist site available
EXTRACT_SUFX=	# empty

MAINTAINER=	cjep@NetBSD.org
COMMENT=	Extract zoo archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-extract:
	cd ${DISTDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} &&	${CC} ${CFLAGS} -DSYS_IS_UNIX -DSYS_HAS_MKDIR -o unzoo unzoo.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unzoo ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
