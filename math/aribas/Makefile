# $NetBSD: Makefile,v 1.5 2001/04/28 23:59:20 jtb Exp $

DISTNAME=	aribas-1.20
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.mathematik.uni-muenchen.de/pub/forster/aribas/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mathematik.uni-muenchen.de/~forster/sw/aribas.html
COMMENT=	Multi-precision floating point and big integer arithmetic calculator

WRKSRC=		${WRKDIR}/aribas/src

MAKE_ENV+=	CPPFLAGS="-DUNiX -DPROTO"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aribas ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/aribas
	${INSTALL_DATA} ${WRKDIR}/aribas/doc/* ${PREFIX}/share/doc/aribas/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/aribas
	${INSTALL_DATA} ${WRKDIR}/aribas/examples/* ${PREFIX}/share/examples/aribas/
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/EL/aribas.el ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
