# $NetBSD: Makefile,v 1.8 2003/12/25 14:46:17 wiz Exp $

DISTNAME=	nut-9.5
CATEGORIES=	biology
MASTER_SITES=	http://www.lafn.org/~av832/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.lafn.org/~av832/
COMMENT=	Record what you eat and analyze your meals

ALL_TARGET=	nut
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nut ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/nut
	${INSTALL_DATA} ${WRKSRC}/raw.data/* ${PREFIX}/share/nut
	${INSTALL_MAN} ${WRKSRC}/nut.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
