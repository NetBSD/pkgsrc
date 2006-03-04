# $NetBSD: Makefile,v 1.9 2006/03/04 21:30:46 jlam Exp $

DISTNAME=	dictionary-1.8.2
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/dictionary/emacs-dict-client/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
