# $NetBSD: Makefile,v 1.8 2008/03/04 15:55:13 jlam Exp $

.include	"../../inputmethod/anthy/Makefile.common"
PKGNAME=	${EMACS_PKGNAME_PREFIX}anthy-elisp-${ANTHY_VERSION}
PKGREVISION=	3
CATEGORIES=	inputmethod editors

MAINTAINER=	taya@NetBSD.org
COMMENT=	Emacs lisp files for inputmethod/anthy

DEPENDS+=	anthy>=${ANTHY_VERSION}:../../inputmethod/anthy

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	EMACS=${EMACS_BIN:Q}
EMACS_MODULES+=	base leim

.include "../../mk/emacs.mk"

do-build:
	cd ${WRKSRC}/src-util && ${MAKE} elc-stamp

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/anthy
	${INSTALL_DATA} ${WRKSRC}/src-util/*.el	 ${DESTDIR}${EMACS_LISPPREFIX}/anthy
	${INSTALL_DATA} ${WRKSRC}/src-util/*.elc ${DESTDIR}${EMACS_LISPPREFIX}/anthy

.include "../../mk/bsd.pkg.mk"
