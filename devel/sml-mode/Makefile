# $NetBSD: Makefile,v 1.6 2003/07/17 21:33:59 grant Exp $

DISTNAME=	sml-mode-3.9.5
CATEGORIES=	devel editors
MASTER_SITES=	ftp://flint.cs.yale.edu/pub/monnier/sml-mode/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Emacs mode for editing Standard ML source code

DEPENDS+=	emacs-[0-9]*:../../editors/emacs

ALL_TARGET=	default

USE_NEW_TEXINFO=	YES
INFO_FILES=	sml-mode.info

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/sml-mode
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc README NEWS TODO \
		ChangeLog ${PREFIX}/share/emacs/site-lisp/sml-mode
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
