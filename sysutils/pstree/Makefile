# $NetBSD: Makefile,v 1.27 2013/05/09 15:41:23 wen Exp $
#

DISTNAME=	pstree-2.36
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.thp.uni-duisburg.de/pub/source/
#		http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display processes in a tree
HOMEPAGE=	http://www.thp.uni-duisburg.de/pstree/

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin share/doc/proctree

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstree ${DESTDIR}${PREFIX}/bin/proctree
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/proctree

.include "../../mk/bsd.pkg.mk"
