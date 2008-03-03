# $NetBSD: Makefile,v 1.17 2008/03/03 17:45:35 jlam Exp $

DISTNAME=		haskell-mode-1.44
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel editors
MASTER_SITES=		http://www.haskell.org/haskell-mode/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.haskell.org/haskell-mode/
COMMENT=		Haskell mode for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/haskell-mode
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${DESTDIR}${EMACS_LISPPREFIX}/haskell-mode
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/haskell-mode
	cd ${WRKSRC} && ${INSTALL_DATA} ${HTML}				\
			${DESTDIR}${PREFIX}/share/doc/html/haskell-mode

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
