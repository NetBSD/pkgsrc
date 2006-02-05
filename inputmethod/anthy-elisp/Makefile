# $NetBSD: Makefile,v 1.5 2006/02/05 23:09:42 joerg Exp $

.include	"../../inputmethod/anthy/Makefile.common"
PKGNAME=	${EMACS_PKGNAME_PREFIX}anthy-elisp-${ANTHY_VERSION}
PKGREVISION=	2
CATEGORIES=	inputmethod editors

MAINTAINER=	taya@NetBSD.org
COMMENT=	Emacs lisp files for inputmethod/anthy

DEPENDS+=	anthy>=${ANTHY_VERSION}:../../inputmethod/anthy

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	EMACS=${EMACS_BIN:Q}
EMACS_USE_LEIM=	yes	# (for emacs21/emacs20)

.include "../../mk/emacs.mk"
.if ${EMACS_FLAVOR} == "xemacs"
DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
.endif

do-build:
	cd ${WRKSRC}/src-util && ${MAKE} elc-stamp

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/anthy
	${INSTALL_DATA} ${WRKSRC}/src-util/*.el	 ${EMACS_LISPPREFIX}/anthy
	${INSTALL_DATA} ${WRKSRC}/src-util/*.elc ${EMACS_LISPPREFIX}/anthy

.include "../../mk/bsd.pkg.mk"
