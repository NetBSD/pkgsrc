# $NetBSD: Makefile,v 1.6 2017/09/03 08:36:58 wiz Exp $

DISTNAME=	md4coll
PKGNAME=	md4-collision-20051118
CATEGORIES=	security
MASTER_SITES=	http://www.stachliu.com/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.stachliu.com/collisions.html
COMMENT=	MD4 Collision generator

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o md4coll md4coll.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/md4coll ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
