# $NetBSD: Makefile,v 1.8 2001/05/02 15:37:21 jtb Exp $
#

DISTNAME=	pstree-2.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	Display processes in a tree

CONFLICTS+=	psmisc-[0-9]*

WRKSRC=		${WRKDIR}

do-build:
		cd ${WRKSRC}; ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pstree
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pstree

.include "../../mk/bsd.pkg.mk"
