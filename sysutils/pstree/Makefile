# $NetBSD: Makefile,v 1.13 2003/06/02 01:16:54 jschauma Exp $
#

DISTNAME=	pstree-2.19
WRKSRC=		${WRKDIR}
CATEGORIES=	sysutils
# PKGREVISION=	1
MASTER_SITES=	http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Display processes in a tree

do-build:
		cd ${WRKSRC}; ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin/proctree
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proctree
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/proctree

.include "../../mk/bsd.pkg.mk"
