# $NetBSD: Makefile,v 1.15 2004/01/20 12:26:16 agc Exp $
#

DISTNAME=	pstree-2.19
CATEGORIES=	sysutils
# PKGREVISION=	1
MASTER_SITES=	http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Display processes in a tree

WRKSRC=		${WRKDIR}

do-build:
		cd ${WRKSRC}; ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin/proctree
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proctree
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/proctree

.include "../../mk/bsd.pkg.mk"
