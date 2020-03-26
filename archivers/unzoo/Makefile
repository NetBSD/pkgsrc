# $NetBSD: Makefile,v 1.15 2020/03/26 22:29:47 rillig Exp $
#

DISTNAME=	unzoo.c
PKGNAME=	unzoo-4.4
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# no dist site available
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extract zoo archives

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-extract:
	cd ${DISTDIR} && ${CP} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} &&	${CC} ${CFLAGS} -DSYS_IS_UNIX -DSYS_HAS_MKDIR -o unzoo unzoo.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unzoo ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
