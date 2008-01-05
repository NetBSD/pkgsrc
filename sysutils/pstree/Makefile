# $NetBSD: Makefile,v 1.21 2008/01/05 20:33:17 heinz Exp $
#

DISTNAME=	pstree-2.32
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.thp.uni-duisburg.de/pub/source/
#		http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display processes in a tree
HOMEPAGE=	http://www.thp.uni-duisburg.de/pstree/

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
		cd ${WRKSRC}; ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree \
			${DESTDIR}${PREFIX}/bin/proctree
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/proctree
		${INSTALL_DATA} ${WRKSRC}/README \
			${DESTDIR}${PREFIX}/share/doc/proctree

.include "../../mk/bsd.pkg.mk"
