# $NetBSD: Makefile,v 1.1.1.1 2002/11/20 08:39:22 tron Exp $

DISTNAME=	dictionary-1.8.2
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://me.in-berlin.de/~myrkr/dictionary/
COMMENT=	Emacs package for talking to a dictionary server

DEPENDS+=	emacs>=21.2:../../editors/emacs21

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/dictionary
	cd ${WRKSRC}; \
	${INSTALL_DATA} connection.elc connection.el dictionary.elc \
	  dictionary.el link.elc link.el dictionary-init.el \
	  ${PREFIX}/share/emacs/site-lisp/dictionary

.include "../../mk/bsd.pkg.mk"
