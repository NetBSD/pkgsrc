# $NetBSD: Makefile,v 1.16 2026/09/25 09:48:12 wiz Exp $

DISTNAME=	dictionary-1.8.2
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/dictionary/dict-client/}
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://me.in-berlin.de/~myrkr/dictionary/
COMMENT=	Emacs package for talking to a dictionary server

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/dictionary

MAKE_FLAGS+=	EMACS=${EMACS_BIN}

do-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} connection.elc connection.el dictionary.elc \
	    dictionary.el link.elc link.el dictionary-init.el \
	    ${DESTDIR}${EMACS_LISPPREFIX}/dictionary

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
