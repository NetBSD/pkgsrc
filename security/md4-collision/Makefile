# $NetBSD: Makefile,v 1.1.1.1 2005/11/18 23:43:05 agc Exp $

DISTNAME=	md4coll
PKGNAME=	md4-collision-20051118
CATEGORIES=	security
MASTER_SITES=	http://www.stachliu.com/
EXTRACT_SUFX=	.c

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.stachliu.com/collisions.html
COMMENT=	MD5 Collision generator

EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o md4coll md4coll.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/md4coll ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
