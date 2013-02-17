# $NetBSD: Makefile,v 1.13 2013/02/17 19:18:08 dholland Exp $

DISTNAME=	dictionary-1.8.2
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/dictionary/emacs-dict-client/}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://me.in-berlin.de/~myrkr/dictionary/
COMMENT=	Emacs package for talking to a dictionary server

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/dictionary

do-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} connection.elc connection.el dictionary.elc \
	    dictionary.el link.elc link.el dictionary-init.el \
	    ${DESTDIR}${EMACS_LISPPREFIX}/dictionary

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
