# $NetBSD: Makefile,v 1.20 2005/06/16 06:57:40 jlam Exp $

DISTNAME=	nut-10.18
CATEGORIES=	biology
MASTER_SITES=	http://www.lafn.org/~av832/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.lafn.org/~av832/
COMMENT=	Record what you eat and analyze your meals

BUILD_TARGET=	nut
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nut ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/nut
	${INSTALL_DATA} ${WRKSRC}/raw.data/* ${PREFIX}/share/nut
	${INSTALL_MAN} ${WRKSRC}/nut.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
