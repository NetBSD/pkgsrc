# $NetBSD: Makefile,v 1.3 2001/02/17 17:40:19 wiz Exp $
#

DISTNAME=		esh-0.8
CATEGORIES=		shells
MASTER_SITES=		http://esh.netpedia.net/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://esh.netpedia.net
COMMENT=		Unix shell with Lisp-like syntax

WRKSRC=			${WRKDIR}/esh
INFO_FILES=		esh.info

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/esh
	${INSTALL_DATA} ${WRKSRC}/examples/*.esh ${PREFIX}/share/examples/esh
.if !exists(${PREFIX}/share/emacs/site-lisp)
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
.endif
	${INSTALL_DATA} ${WRKSRC}/emacs/esh-mode.el ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/doc/esh.info ${PREFIX}/info
	${MKDIR} ${PREFIX}/share/doc/esh
	@for i in esh.html esh_toc.html ; do \
	${INSTALL_DATA} ${WRKSRC}/doc/$$i ${PREFIX}/share/doc/esh/$$i; done

.include "../../mk/bsd.pkg.mk"
