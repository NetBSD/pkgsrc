# $NetBSD: Makefile,v 1.1.1.1 2000/11/02 21:51:58 tron Exp $
#

DISTNAME=		esh-0.8
CATEGORIES=		shells
MASTER_SITES=		http://esh.netpedia.net/

MAINTAINER=		jasontd@indigo.ie
HOMEPAGE=		http://esh.netpedia.net

WRKSRC=			${WRKDIR}/esh
INFO_FILES=		esh.info

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/esh
	@(cd ${WRKSRC}/examples	; 					\
		for i in *.esh ; do					\
		${CP} $$i ${PREFIX}/share/examples/esh;			\
		done)
	${INSTALL_DATA} ${WRKSRC}/emacs/esh-mode.el 			\
	${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/doc/esh.info ${PREFIX}/info
	${MKDIR} ${PREFIX}/share/doc/esh
	@(for i in esh.html esh_toc.html; do				\
	${INSTALL_DATA} ${WRKSRC}/doc/$$i ${PREFIX}/share/doc/esh/$$i; 	\
	done)

.include "../../mk/bsd.pkg.mk"
