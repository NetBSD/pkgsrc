# $NetBSD: Makefile,v 1.1.1.1 2000/11/25 19:56:25 jtb Exp $

DISTNAME=	aribas-1.14
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.mathematik.uni-muenchen.de/pub/forster/aribas/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.mathematik.uni-muenchen.de/~forster/sw/aribas.html

WRKSRC=		${WRKDIR}/aribas/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aribas ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/aribas
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${PREFIX}/share/doc/aribas
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/aribas
	${INSTALL_DATA} ${WRKSRC}/../examples/* ${PREFIX}/share/examples/aribas
.if !exists(${PREFIX}/share/emacs/site-lisp)
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
.endif
	${INSTALL_DATA} ${WRKSRC}/EL/aribas.el ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
