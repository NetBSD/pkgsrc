# $NetBSD: Makefile,v 1.19 2007/04/30 02:49:15 obache Exp $
#

DISTNAME=	pstree-2.27
CATEGORIES=	sysutils
# PKGREVISION=	1
MASTER_SITES=	ftp://ftp.thp.uni-duisburg.de/pub/source/ \
		http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display processes in a tree
HOMEPAGE=	http://www.thp.uni-duisburg.de/pstree/

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
		cd ${WRKSRC}; ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin/proctree
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proctree
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/proctree

.include "../../mk/bsd.pkg.mk"
