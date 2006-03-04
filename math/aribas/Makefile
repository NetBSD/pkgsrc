# $NetBSD: Makefile,v 1.15 2006/03/04 21:30:02 jlam Exp $

DISTNAME=	aribas-1.53
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.mathematik.uni-muenchen.de/pub/forster/aribas/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mathematik.uni-muenchen.de/~forster/sw/aribas.html
COMMENT=	Multi-precision floating point and big integer arithmetic calculator

CPPFLAGS+=	-DUNiX -DPROTO

BUILD_DIRS=	src

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aribas ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/aribas.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/aribas
	${INSTALL_DATA} ${WRKSRC}/doc/aribas.[dmt]* ${PREFIX}/share/doc/aribas/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/aribas
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/aribas/
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/src/EL/aribas.el ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
