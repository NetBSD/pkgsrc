# $NetBSD: Makefile,v 1.1.1.1 2001/04/14 23:08:58 jtb Exp $

DISTNAME=	sml-mode-3.9.5
CATEGORIES=	devel editors
MASTER_SITES=	ftp://flint.cs.yale.edu/pub/monnier/sml-mode/

MAINTAINER=	packages@netbsd.org
COMMENT=	Emacs mode for editing Standard ML source code

ALL_TARGET=	default

INFO_FILES=	sml-mode.info

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/sml-mode
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc README NEWS TODO \
		ChangeLog ${PREFIX}/share/emacs/site-lisp/sml-mode
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
