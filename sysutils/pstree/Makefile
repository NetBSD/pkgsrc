# $NetBSD: Makefile,v 1.3 2000/12/15 12:36:03 mjl Exp $
#

DISTNAME=	pstree-2.16
CATEGORIES=	sysutils
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/contrib/

MAINTAINER=	packages@netbsd.org

CONFLICTS+=	psmisc-*

WRKSRC=		${WRKDIR}

do-build:
		cd ${WRKSRC}; cc -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pstree
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pstree

.include "../../mk/bsd.pkg.mk"
