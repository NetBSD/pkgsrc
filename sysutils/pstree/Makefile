# $NetBSD: Makefile,v 1.10 2002/12/25 22:44:53 mjl Exp $
#

DISTNAME=	pstree-2.17
CATEGORIES=	sysutils
# PKGREVISION=	1
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	Display processes in a tree

WRKSRC=		${WRKDIR}

do-build:
		cd ${WRKSRC}; ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin/proctree
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proctree
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/proctree

.include "../../mk/bsd.pkg.mk"
