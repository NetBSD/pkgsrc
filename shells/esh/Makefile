# $NetBSD: Makefile,v 1.5 2001/03/08 21:26:50 jtb Exp $
#
# XXX MASTER_SITES and HOMEPAGE are commented out as they now require
# authorization for access.
#

DISTNAME=		esh-0.8
CATEGORIES=		shells
#MASTER_SITES=		http://esh.netpedia.net/

MAINTAINER=		jtb@netbsd.org
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
	@for i in esh.html esh_toc.html ; do				\
	${INSTALL_DATA} ${WRKSRC}/doc/$$i ${PREFIX}/share/doc/esh/$$i;	\
	done

.include "../../mk/bsd.pkg.mk"
