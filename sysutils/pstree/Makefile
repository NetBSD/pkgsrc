# $NetBSD: Makefile,v 1.5 2001/02/17 17:42:17 wiz Exp $
#

DISTNAME=	pstree-2.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	Display processes in a tree

CONFLICTS+=	psmisc-*

WRKSRC=		${WRKDIR}

do-build:
		cd ${WRKSRC}; cc -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pstree
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pstree

.include "../../mk/bsd.pkg.mk"
