# $NetBSD: Makefile,v 1.24 2022/05/14 22:25:34 dholland Exp $

DISTNAME=		haskell-mode-1.44
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		5
CATEGORIES=		devel editors
MASTER_SITES=		http://www.haskell.org/haskell-mode/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.haskell.org/haskellwiki/Haskell_mode_for_Emacs
COMMENT=		Haskell mode for Emacs

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/haskell-mode \
			share/doc/haskell-mode

HTML=	.emacs fontlock.hs indent.hs index.html installation-guide.html
SRCS=	haskell-decl-scan.el haskell-doc.el haskell-font-lock.el	\
	haskell-ghci.el haskell-hugs.el haskell-indent.el		\
	haskell-mode.el haskell-simple-indent.el

do-build:
	for f in ${SRCS}; do						\
		${EMACS_BIN} --no-init-file --no-site-file -batch	\
		-f batch-byte-compile ${WRKSRC}/$$f;			\
	done

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${DESTDIR}${EMACS_LISPPREFIX}/haskell-mode
	cd ${WRKSRC} && ${INSTALL_DATA} ${HTML}				\
			${DESTDIR}${PREFIX}/share/doc/haskell-mode

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
