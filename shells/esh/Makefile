# $NetBSD: Makefile,v 1.19 2005/06/17 03:50:33 jlam Exp $

DISTNAME=		esh-0.8
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Unix shell with Lisp-like syntax

INFO_FILES=		esh.info

WRKSRC=			${WRKDIR}/esh
USE_PKGINSTALL=		yes
PKG_SHELL=		${PREFIX}/bin/esh
INSTALLATION_DIRS=	bin info

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

.include "../../mk/bsd.pkg.mk"
