# $NetBSD: Makefile,v 1.3 2006/03/04 21:30:35 jlam Exp $

DISTNAME=	md4coll
PKGNAME=	md4-collision-20051118
CATEGORIES=	security
MASTER_SITES=	http://www.stachliu.com/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stachliu.com/collisions.html
COMMENT=	MD5 Collision generator

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o md4coll md4coll.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/md4coll ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
