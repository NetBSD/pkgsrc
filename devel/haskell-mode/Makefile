# $NetBSD: Makefile,v 1.5 2001/04/28 23:59:18 jtb Exp $

DISTNAME=		haskell-mode-20001129
CATEGORIES=		devel editors
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.haskell.org/haskell-mode/
COMMENT=		Haskell mode for Emacs

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	 	xemacs-[0-9]*:../../editors/xemacs
EMACS=			xemacs
LISPDIR=		lib/xemacs/xemacs-packages/lisp/prog-modes
.else
DEPENDS+=	 	emacs-[0-9]*:../../editors/emacs
EMACS=			emacs
LISPDIR=		share/emacs/site-lisp/haskell-mode
.endif

PLIST_SUBST+=		LISPDIR=${LISPDIR}

SRCS= 	haskell-doc.el haskell-mode.el haskell-font-lock.el		\
	haskell-simple-indent.el haskell-hugs.el haskell-decl-scan.el	\
	haskell-indent.el

do-build:
	for f in ${SRCS}; do \
	${EMACS} --no-init-file --no-site-file -batch -f batch-byte-compile ${WRKSRC}/$$f; \
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${PREFIX}/${LISPDIR}

.include "../../mk/bsd.pkg.mk"
