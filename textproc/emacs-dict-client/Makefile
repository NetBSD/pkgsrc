# $NetBSD: Makefile,v 1.6 2003/09/09 23:51:21 jschauma Exp $

DISTNAME=	dictionary-1.8.2
PKGNAME=	${DISTNAME:S/dictionary/emacs-dict-client/}
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://me.in-berlin.de/~myrkr/dictionary/
COMMENT=	Emacs package for talking to a dictionary server

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/dictionary
	cd ${WRKSRC}; \
	${INSTALL_DATA} connection.elc connection.el dictionary.elc \
	  dictionary.el link.elc link.el dictionary-init.el \
	  ${PREFIX}/share/emacs/site-lisp/dictionary

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
