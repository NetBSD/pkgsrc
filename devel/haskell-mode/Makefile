# $NetBSD: Makefile,v 1.9 2002/09/14 03:20:28 uebayasi Exp $

DISTNAME=		haskell-mode-1.43
CATEGORIES=		devel editors
MASTER_SITES=		http://www.haskell.org/haskell-mode/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.haskell.org/haskell-mode/
COMMENT=		Haskell mode for Emacs

WRKSRC=			${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
EMACS=	"emacs"
.else
EMACS=	"xemacs"
.endif

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
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/haskell-mode
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${EMACS_LISPPREFIX}/haskell-mode
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/haskell-mode
	cd ${WRKSRC} && ${INSTALL_DATA} ${HTML}				\
			${PREFIX}/share/doc/html/haskell-mode

.include "../../mk/bsd.pkg.mk"
