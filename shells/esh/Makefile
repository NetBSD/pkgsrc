# $NetBSD: Makefile,v 1.12 2003/01/28 22:04:11 jlam Exp $

DISTNAME=		esh-0.8
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		packages@netbsd.org
COMMENT=		Unix shell with Lisp-like syntax

WRKSRC=			${WRKDIR}/esh
INFO_FILES=		esh.info

USE_PKGINSTALL=		yes
PKG_SHELL=		${PREFIX}/bin/esh

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
		${PREFIX}/share/doc/esh/

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
