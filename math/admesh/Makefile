# $NetBSD: Makefile,v 1.5 2003/06/02 01:18:36 jschauma Exp $

DISTNAME=		admesh-0.95
CATEGORIES=		math
MASTER_SITES=		http://www.varlog.com/products/admesh/files/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.varlog.com/products/admesh/
COMMENT=		Program for processing triangulated solid meshes

GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/admesh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/admesh
	cd ${WRKSRC} && ${INSTALL_DATA} README ADMESH.DOC		\
		${PREFIX}/share/doc/admesh/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/admesh
	${INSTALL_DATA} ${WRKSRC}/block.stl ${PREFIX}/share/examples/admesh

.include "../../mk/bsd.pkg.mk"
