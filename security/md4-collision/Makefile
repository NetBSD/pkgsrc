# $NetBSD: Makefile,v 1.5 2012/10/23 18:16:36 asau Exp $

DISTNAME=	md4coll
PKGNAME=	md4-collision-20051118
CATEGORIES=	security
MASTER_SITES=	http://www.stachliu.com/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stachliu.com/collisions.html
COMMENT=	MD4 Collision generator

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o md4coll md4coll.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/md4coll ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
