# $NetBSD: Makefile,v 1.1.1.1 2000/11/30 02:29:27 jtb Exp $

DISTNAME=		haskell-mode-20001129
CATEGORIES=		devel editors
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.haskell.org/haskell-mode/

DEPENDS+=		emacs-[0-9]*:../../editors/emacs

SRCS= 	haskell-doc.el haskell-mode.el haskell-font-lock.el		\
	haskell-simple-indent.el haskell-hugs.el haskell-decl-scan.el	\
	haskell-indent.el

do-build:
	@for f in ${SRCS} ; do \
	emacs -batch -f batch-byte-compile ${WRKSRC}/$$f 2>/dev/null ; \
	${ECHO} "byte-compiled file" $$f ; done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/haskell-mode
	@for f in ${SRCS} ${SRCS:.el=.elc} ; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/emacs/site-lisp/haskell-mode ; \
	done

.include "../../mk/bsd.pkg.mk"
