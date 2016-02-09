# $NetBSD: Makefile,v 1.28 2016/02/09 14:27:57 mef Exp $
#

DISTNAME=	pstree-2.39
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.thp.uni-duisburg.de/pub/source/
#		http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display processes in a tree
HOMEPAGE=	http://www.thp.uni-duisburg.de/pstree/
LICENSE=	gnu-gpl-v1

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin share/doc/proctree

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstree ${DESTDIR}${PREFIX}/bin/proctree
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/proctree

.include "../../mk/bsd.pkg.mk"
