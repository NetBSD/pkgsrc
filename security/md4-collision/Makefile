# $NetBSD: Makefile,v 1.4 2010/01/27 14:28:28 joerg Exp $

DISTNAME=	md4coll
PKGNAME=	md4-collision-20051118
CATEGORIES=	security
MASTER_SITES=	http://www.stachliu.com/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stachliu.com/collisions.html
COMMENT=	MD4 Collision generator

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o md4coll md4coll.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/md4coll ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
