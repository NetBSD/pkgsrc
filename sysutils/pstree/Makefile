# $NetBSD: Makefile,v 1.2 2000/09/03 13:30:05 wiz Exp $
#

DISTNAME=	pstree-2.14
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
