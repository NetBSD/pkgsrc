# $NetBSD: Makefile,v 1.3 2003/04/15 22:08:54 jmc Exp $

DISTNAME=	dictionary-1.8.2
PKGNAME=	${DISTNAME:S/dictionary/emacs-dict-client/}
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://me.in-berlin.de/~myrkr/dictionary/
COMMENT=	Emacs package for talking to a dictionary server

DEPENDS+=	emacs>=21.2:../../editors/emacs

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/dictionary
	cd ${WRKSRC}; \
	${INSTALL_DATA} connection.elc connection.el dictionary.elc \
	  dictionary.el link.elc link.el dictionary-init.el \
	  ${PREFIX}/share/emacs/site-lisp/dictionary

.include "../../mk/bsd.pkg.mk"
