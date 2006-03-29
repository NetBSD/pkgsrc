# $NetBSD: Makefile,v 1.18 2006/03/29 21:31:48 ghen Exp $
#

DISTNAME=	pstree-2.27
CATEGORIES=	sysutils
# PKGREVISION=	1
MASTER_SITES=	http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display processes in a tree

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
		cd ${WRKSRC}; ${CC} ${CFLAGS} -o pstree pstree.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pstree ${PREFIX}/bin/proctree
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proctree
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/proctree

.include "../../mk/bsd.pkg.mk"
