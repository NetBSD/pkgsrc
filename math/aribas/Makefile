# $NetBSD: Makefile,v 1.10 2003/07/17 21:47:20 grant Exp $

DISTNAME=	aribas-1.30
WRKSRC=		${WRKDIR}/aribas/src
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.mathematik.uni-muenchen.de/pub/forster/aribas/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mathematik.uni-muenchen.de/~forster/sw/aribas.html
COMMENT=	Multi-precision floating point and big integer arithmetic calculator

CPPFLAGS+=	-DUNiX -DPROTO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aribas ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/aribas
	${INSTALL_DATA} ${WRKDIR}/aribas/doc/* ${PREFIX}/share/doc/aribas/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/aribas
	${INSTALL_DATA} ${WRKDIR}/aribas/examples/* ${PREFIX}/share/examples/aribas/
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/EL/aribas.el ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
