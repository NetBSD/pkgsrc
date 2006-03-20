# $NetBSD: Makefile,v 1.6 2006/03/20 05:27:50 jlam Exp $

.include	"../../inputmethod/anthy/Makefile.common"
PKGNAME=	${EMACS_PKGNAME_PREFIX}anthy-elisp-${ANTHY_VERSION}
PKGREVISION=	2
CATEGORIES=	inputmethod editors

MAINTAINER=	taya@NetBSD.org
COMMENT=	Emacs lisp files for inputmethod/anthy

DEPENDS+=	anthy>=${ANTHY_VERSION}:../../inputmethod/anthy

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	EMACS=${EMACS_BIN:Q}
EMACS_MODULES+=	base leim

.include "../../mk/emacs.mk"

do-build:
	cd ${WRKSRC}/src-util && ${MAKE} elc-stamp

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/anthy
	${INSTALL_DATA} ${WRKSRC}/src-util/*.el	 ${EMACS_LISPPREFIX}/anthy
	${INSTALL_DATA} ${WRKSRC}/src-util/*.elc ${EMACS_LISPPREFIX}/anthy

.include "../../mk/bsd.pkg.mk"
