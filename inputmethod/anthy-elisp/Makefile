# $NetBSD: Makefile,v 1.12 2013/02/17 19:18:03 dholland Exp $

.include	"../../inputmethod/anthy/Makefile.common"
PKGNAME=	${EMACS_PKGNAME_PREFIX}anthy-elisp-${ANTHY_VERSION}
PKGREVISION=	5
CATEGORIES=	inputmethod editors

MAINTAINER=	taya@NetBSD.org
COMMENT=	Emacs lisp files for inputmethod/anthy

DEPENDS+=	anthy>=${ANTHY_VERSION}:../../inputmethod/anthy

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	EMACS=${EMACS_BIN:Q}
EMACS_MODULES+=	base leim

.include "../../editors/emacs/modules.mk"

do-build:
	cd ${WRKSRC}/src-util && ${MAKE} elc-stamp

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/anthy
	${INSTALL_DATA} ${WRKSRC}/src-util/*.el	 ${DESTDIR}${EMACS_LISPPREFIX}/anthy
	${INSTALL_DATA} ${WRKSRC}/src-util/*.elc ${DESTDIR}${EMACS_LISPPREFIX}/anthy

.include "../../mk/bsd.pkg.mk"
