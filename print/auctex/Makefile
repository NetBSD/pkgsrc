# $NetBSD: Makefile,v 1.7 2002/02/18 15:14:37 seb Exp $

DISTNAME=		auctex-10.0g
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.sunsite.auc.dk/pub/emacs/auctex/ftp/auctex/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://sunsite.auc.dk/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

DEPENDS+=		teTeX-[0-9]*:../../print/teTeX

USE_GMAKE=		#defined

TEX_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		TEX_PREFIX=teTeX

.if defined(USE_XEMACS)
DEPENDS+=		xemacs-[0-9]*:../../editors/xemacs
MAKE_ENV+=		EMACS=xemacs
LISPDIR=		lib/xemacs/xemacs-packages/lisp
INFODIR=		lib/xemacs/xemacs-packages/info
.else
DEPENDS+=		emacs-[0-9]*:../../editors/emacs
MAKE_ENV+=		EMACS=emacs
LISPDIR=		share/emacs/site-lisp
INFODIR=		info
INFO_FILES+=		auctex
.endif

PLIST_SUBST+=		LISPDIR=${LISPDIR} INFODIR=${INFODIR}
MESSAGE_SUBST+=		LISPDIR=${LISPDIR}

post-patch:
	${MV} ${WRKSRC}/tex-site.el ${WRKSRC}/tex-site.el.orig
	${SED} -e 's:@LISPDIR@:'${LISPDIR}':g'			\
		-e 's:@TEX_PREFIX@:'${TEX_PREFIX}':g'		\
	${WRKSRC}/tex-site.el.orig > ${WRKSRC}/tex-site.el
	${CP} ${WRKSRC}/tex-site.el ${WRKSRC}/tex-site.el.dist

post-build:
	${RM} -f ${WRKSRC}/doc/auctex*
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} auctex

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}/auctex
	${INSTALL_DATA} ${WRKSRC}/tex-site.el ${PREFIX}/${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/tex-site.el.dist ${PREFIX}/${LISPDIR}
.if !exists(${PREFIX}/${LISPDIR}/tex-site.el)
	${INSTALL_DATA} ${WRKSRC}/tex-site.el ${PREFIX}/${LISPDIR}
.endif
	for f in auc-old.el bib-cite.el font-latex.el hilit-LaTeX.el	   \
	latex.el lpath.el multi-prompt.el tex-buf.el tex-info.el tex-jp.el \
	tex.el texmathp.el; do						   \
	${INSTALL_DATA} ${WRKSRC}/$$f* ${PREFIX}/${LISPDIR}/auctex/; 	   \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}/auctex/style
	${INSTALL_DATA} ${WRKSRC}/style/*.el* ${PREFIX}/${LISPDIR}/auctex/style
	${INSTALL_DATA} ${WRKSRC}/doc/auctex* ${PREFIX}/${INFODIR}

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
