# $NetBSD: Makefile,v 1.9 2002/09/16 03:31:26 uebayasi Exp $

DISTNAME=		auctex-11.11
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.sunsite.auc.dk/pub/emacs/auctex/ftp/auctex/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://sunsite.auc.dk/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

DEPENDS+=		teTeX-[0-9]*:../../print/teTeX

USE_GMAKE=		#defined

TEX_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		TEX_PREFIX=teTeX

MAKEFLAGS+=		EMACS=${EMACS_BIN}

.if defined(USE_XEMACS)
LISPDIR=		${EMACS_LISPPREFIX}
INFODIR=		${EMACS_LISPPREFIX}/../info
.else
LISPDIR=		${EMACS_LISPPREFIX}
INFODIR=		info
INFO_FILES+=		auctex
.endif

PLIST_SUBST+=		INFODIR=${INFODIR}
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
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/auctex
	${INSTALL_DATA} ${WRKSRC}/tex-site.el ${EMACS_LISPPREFIX}/auctex
	${INSTALL_DATA} ${WRKSRC}/tex-site.el.dist ${EMACS_LISPPREFIX}/auctex
.if !exists(${EMACS_LISPPREFIX}/auctex/tex-site.el)
	${INSTALL_DATA} ${WRKSRC}/tex-site.el ${EMACS_LISPPREFIX}/auctex/tex-site.el
.endif
	for f in auc-old.el bib-cite.el font-latex.el hilit-LaTeX.el	   \
	latex.el lpath.el multi-prompt.el tex-buf.el tex-info.el tex-jp.el \
	tex.el texmathp.el; do						   \
	${INSTALL_DATA} ${WRKSRC}/$$f* ${EMACS_LISPPREFIX}/auctex; 	   \
	done
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/auctex/style
	${INSTALL_DATA} ${WRKSRC}/style/*.el* ${EMACS_LISPPREFIX}/auctex/style
	${INSTALL_DATA} ${WRKSRC}/doc/auctex* ${PREFIX}/${INFODIR}

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
