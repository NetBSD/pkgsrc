# $NetBSD: Makefile,v 1.1.1.1 2001/02/10 04:44:57 jtb Exp $

DISTNAME=		admesh-0.95
CATEGORIES=		math
MASTER_SITES=		http://www.varlog.com/products/admesh/files/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.varlog.com/products/admesh/

GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/admesh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/admesh
	@for f in README ADMESH.DOC; do					\
	i="${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/admesh/";	\
	${ECHO} $$i; $$i;						\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/admesh
	${INSTALL_DATA} ${WRKSRC}/block.stl ${PREFIX}/share/examples/admesh

.include "../../mk/bsd.pkg.mk"
