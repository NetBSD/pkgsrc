# $NetBSD: Makefile,v 1.24 2006/04/07 15:28:49 jlam Exp $

DISTNAME=		esh-0.8
PKGREVISION=		1
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Unix shell with Lisp-like syntax

WRKSRC=			${WRKDIR}/esh
PKG_SHELL=		bin/esh
INFO_FILES=		# PLIST
INSTALLATION_DIRS=	bin ${PKGINFODIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/esh
	${INSTALL_DATA} ${WRKSRC}/examples/*.esh 			\
		${PREFIX}/share/examples/esh
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/emacs/esh-mode.el 			\
		${PREFIX}/share/emacs/site-lisp
	cd ${WRKSRC}/doc; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/esh
	cd ${WRKSRC}/doc && ${INSTALL_DATA} esh.html esh_toc.html	\
		${PREFIX}/share/doc/esh/

.include "../../mk/bsd.pkg.mk"
