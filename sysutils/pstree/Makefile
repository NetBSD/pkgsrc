# $NetBSD: Makefile,v 1.7 2001/05/01 22:06:33 jtb Exp $
#

DISTNAME=	pstree-2.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	Display processes in a tree

CONFLICTS+=	psmisc-[0-9]*

WRKSRC=		${WRKDIR}

do-build:
		cd ${WRKSRC}; ${CC} -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pstree
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pstree

.include "../../mk/bsd.pkg.mk"
