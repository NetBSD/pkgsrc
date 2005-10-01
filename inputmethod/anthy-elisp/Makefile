# $NetBSD: Makefile,v 1.3 2005/10/01 12:47:55 taya Exp $

.include	"../../inputmethod/anthy/Makefile.common"
PKGNAME=	${EMACS_PKGNAME_PREFIX}anthy-elisp-${ANTHY_VERSION}
CATEGORIES=	inputmethod editor
PKGREVISION=	1

MAINTAINER=	taya@NetBSD.org
COMMENT=	Emacs lisp files for inputmethod/anthy

DEPENDS+=	anthy>=${ANTHY_VERSION}:../../inputmethod/anthy

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	EMACS=${EMACS_BIN}
EMACS_USE_LEIM=	# defined (for emacs21/emacs20)

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
