# $NetBSD: Makefile,v 1.3 2001/03/01 18:50:05 jtb Exp $

DISTNAME=	auctex-9.9p
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.sunsite.auc.dk/pub/emacs/auctex/ftp/auctex/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://sunsite.auc.dk/auctex/
COMMENT=	Enhanced LaTeX mode for Emacs

DEPENDS+=	teTeX-[0-9]*:../../print/teTeX

USE_GMAKE=	#defined
EVAL_PREFIX+=	TEX_PREFIX=teTeX

.if defined(USE_XEMACS)
DEPENDS+=	xemacs-[0-9]*:../../editors/xemacs
MAKE_ENV+=	EMACS=xemacs
LISPDIR=	lib/xemacs/xemacs-packages/lisp
INFODIR=	lib/xemacs/xemacs-packages/info
.else
DEPENDS+=	emacs-[0-9]*:../../editors/emacs
MAKE_ENV+=	EMACS=emacs
LISPDIR=	share/emacs/site-lisp
INFODIR=	info
INFO_FILES+=	auctex
.endif

PLIST_SUBST+=	LISPDIR=${LISPDIR} INFODIR=${INFODIR}

post-patch:
	@for t in ${WRKSRC}/tex-site.el; do			\
	${SED} -e 's:@LISPDIR@:'${LISPDIR}':g'			\
		-e 's:@TEX_PREFIX@:'${TEX_PREFIX}':g'		\
		< $$t > $$t.tmp && ${MV} $$t.tmp $$t;		\
	done
	${CP} ${WRKSRC}/tex-site.el ${WRKSRC}/tex-site.el.dist

post-build:
	${RM} -f ${WRKSRC}/doc/auctex*
	cd ${WRKSRC}/doc && ${MAKE} auctex

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}/auctex
	${INSTALL_DATA} ${WRKSRC}/tex-site.el ${PREFIX}/${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/tex-site.el.dist ${PREFIX}/${LISPDIR}
.if !exists(${PREFIX}/${LISPDIR}/tex-site.el)
	${INSTALL_DATA} ${WRKSRC}/tex-site.el ${PREFIX}/${LISPDIR}
.endif
	@for e in auc-old.el bib-cite.el font-latex.el hilit-LaTeX.el	   \
	latex.el lpath.el multi-prompt.el tex-buf.el tex-info.el tex-jp.el \
	tex.el texmathp.el; do						   \
	i="${INSTALL_DATA} ${WRKSRC}/$$e* ${PREFIX}/${LISPDIR}/auctex/";   \
	${ECHO} $$i; $$i;						   \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}/auctex/style
	${INSTALL_DATA} ${WRKSRC}/style/*.el* ${PREFIX}/${LISPDIR}/auctex/style
	${INSTALL_DATA} ${WRKSRC}/doc/auctex* ${PREFIX}/${INFODIR}

.include "../../mk/bsd.pkg.mk"
