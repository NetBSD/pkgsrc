# $NetBSD: Makefile,v 1.8 2001/04/29 01:15:07 jtb Exp $
#
# XXX MASTER_SITES and HOMEPAGE are commented out as they now require
# authorization for access.
#

DISTNAME=		esh-0.8
CATEGORIES=		shells
#MASTER_SITES=		http://esh.netpedia.net/

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=		http://esh.netpedia.net
COMMENT=		Unix shell with Lisp-like syntax

WRKSRC=			${WRKDIR}/esh
INFO_FILES=		esh.info

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/esh
	${INSTALL_DATA} ${WRKSRC}/examples/*.esh 			\
		${PREFIX}/share/examples/esh
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/emacs/esh-mode.el 			\
		${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/doc/esh.info ${PREFIX}/info
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/esh
	cd ${WRKSRC}/doc && ${INSTALL_DATA} esh.html esh_toc.html	\
		${PREFIX}/share/doc/esh/$$i

.include "../../mk/bsd.pkg.mk"
