# $NetBSD: Makefile,v 1.8 2002/09/07 11:07:55 kristerw Exp $

DISTNAME=		haskell-mode-1.43
CATEGORIES=		devel editors
MASTER_SITES=		http://www.haskell.org/haskell-mode/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.haskell.org/haskell-mode/
COMMENT=		Haskell mode for Emacs

WRKSRC=			${WRKDIR}

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

HTML=	.emacs fontlock.hs indent.hs index.html installation-guide.html
SRCS=	haskell-decl-scan.el haskell-doc.el haskell-font-lock.el	\
	haskell-ghci.el haskell-hugs.el haskell-indent.el		\
	haskell-mode.el haskell-simple-indent.el

do-build:
	for f in ${SRCS}; do						\
		${EMACS} --no-init-file --no-site-file -batch		\
		-f batch-byte-compile ${WRKSRC}/$$f;			\
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${PREFIX}/${LISPDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/haskell-mode
	cd ${WRKSRC} && ${INSTALL_DATA} ${HTML}				\
			${PREFIX}/share/doc/html/haskell-mode

.include "../../mk/bsd.pkg.mk"
