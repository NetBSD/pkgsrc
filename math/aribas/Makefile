# $NetBSD: Makefile,v 1.4 2001/04/14 21:43:50 jtb Exp $

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
	@for f in ${WRKDIR}/aribas/doc/*; do \
		i="${INSTALL_DATA} $$f ${PREFIX}/share/doc/aribas/"; \
		${ECHO} $$i; $$i; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/aribas
	@for f in ${WRKDIR}/aribas/examples/*; do \
		i="${INSTALL_DATA} $$f ${PREFIX}/share/examples/aribas/"; \
		${ECHO} $$i; $$i; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/EL/aribas.el ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
