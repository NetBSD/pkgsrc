# $NetBSD: Makefile,v 1.12 2004/08/15 12:06:34 wiz Exp $

DISTNAME=	nut-10.1
CATEGORIES=	biology
MASTER_SITES=	http://www.lafn.org/~av832/
EXTRACT_SUFX=	.tar.bz2

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
