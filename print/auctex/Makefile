# $NetBSD: Makefile,v 1.1.1.1 2000/12/02 07:49:25 jtb Exp $

DISTNAME=		auctex-9.9p
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.sunsite.auc.dk/pub/emacs/auctex/ftp/auctex/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://sunsite.auc.dk/auctex/

DEPENDS+=		teTeX-[0-9]*:../../print/teTeX

USE_GMAKE=		YES

INFO_FILES+=		auctex

EVAL_PREFIX+=		TEX_PREFIX=teTeX

.if defined(USE_XEMACS)
DEPENDS+=		xemacs-[0-9]*:../../editors/xemacs
MAKE_ENV+=		EMACS=xemacs
.else
DEPENDS+=		emacs-[0-9]*:../../editors/emacs
.endif

post-patch:
	@for t in ${WRKSRC}/tex-site.el ; do \
	${SED} -e 's:%%PREFIX%%:'${PREFIX}':g;s:%%TEX_PREFIX%%:'${TEX_PREFIX}':g' \
	< $$t > $$t.tmp && ${MV} $$t.tmp $$t ; done
	@${CP} ${WRKSRC}/tex-site.el ${WRKSRC}/tex-site.el.dist

post-build:
	@${RM} -fr ${WRKSRC}/doc/auctex*
	@cd ${WRKSRC}/doc && ${MAKE} auctex

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/auctex
	${INSTALL_DATA} ${WRKSRC}/tex-site.el ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/tex-site.el.dist \
	${PREFIX}/share/emacs/site-lisp
.if !exists(${PREFIX}/share/emacs/site-lisp/tex-site.el)
	${INSTALL_DATA} ${WRKSRC}/tex-site.el ${PREFIX}/share/emacs/site-lisp
.endif
	@for e in auc-old.el bib-cite.el font-latex.el hilit-LaTeX.el \
	latex.el lpath.el multi-prompt.el tex-buf.el tex-info.el tex-jp.el \
	tex.el texmathp.el ; do \
	${INSTALL_DATA} ${WRKSRC}/$$e* ${PREFIX}/share/emacs/site-lisp/auctex; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/auctex/style
	${INSTALL_DATA} ${WRKSRC}/style/*.el* \
	${PREFIX}/share/emacs/site-lisp/auctex/style
	${INSTALL_DATA} ${WRKSRC}/doc/auctex* ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
