# $NetBSD: Makefile,v 1.16 2003/08/05 11:43:17 seb Exp $

DISTNAME=		esh-0.8
WRKSRC=			${WRKDIR}/esh
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Unix shell with Lisp-like syntax

USE_NEW_TEXINFO=	YES
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

.include "../../mk/bsd.pkg.mk"
