# $NetBSD: Makefile,v 1.11 2004/08/14 15:51:37 snj Exp $

DISTNAME=	nut-9.11
CATEGORIES=	biology
MASTER_SITES=	http://www.lafn.org/~av832/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.lafn.org/~av832/
COMMENT=	Record what you eat and analyze your meals

ALL_TARGET=	nut
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nut ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/nut
	${INSTALL_DATA} ${WRKSRC}/raw.data/* ${PREFIX}/share/nut
	${INSTALL_MAN} ${WRKSRC}/nut.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
