# $NetBSD: Makefile,v 1.23 2006/03/04 21:30:39 jlam Exp $

DISTNAME=		esh-0.8
PKGREVISION=		1
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Unix shell with Lisp-like syntax

INFO_FILES=		esh.info

WRKSRC=			${WRKDIR}/esh
PKG_SHELL=		bin/esh
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
