# $NetBSD: Makefile,v 1.19 2005/06/17 03:50:30 jlam Exp $

DISTNAME=		auctex-11.13
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		http://savannah.nongnu.org/download/auctex/stable.pkg/11.13/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs

USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes

TEX_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		TEX_PREFIX=teTeX

MAKEFLAGS+=		EMACS=${EMACS_BIN}

USE_MAKEINFO=		YES

.if defined(USE_XEMACS)
LISPDIR=		${EMACS_LISPPREFIX}
INFODIR=		${EMACS_LISPPREFIX}/../info
.else
LISPDIR=		${EMACS_LISPPREFIX}
INFODIR=		info
INFO_FILES=		auctex
.endif

PLIST_SUBST+=		INFODIR=${INFODIR}
MESSAGE_SUBST+=		LISPDIR=${LISPDIR}

EGDIR=			${PREFIX}/share/examples/auctex
CONF_FILES=		${EGDIR}/tex-site.el ${EMACS_LISPPREFIX}/auctex/tex-site.el

INSTALLATION_DIRS=	${INFODIR}

post-patch:
	${MV} ${WRKSRC}/tex-site.el ${WRKSRC}/tex-site.el.orig
	${SED} -e 's:@LISPDIR@:'${LISPDIR}':g'			\
		-e 's:@TEX_PREFIX@:'${TEX_PREFIX}':g'		\
	${WRKSRC}/tex-site.el.orig > ${WRKSRC}/tex-site.el
#	${CP} ${WRKSRC}/tex-site.el ${WRKSRC}/tex-site.el.dist

post-build:
	${RM} -f ${WRKSRC}/doc/auctex*
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} auctex

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/tex-site.el ${EGDIR}
#	${INSTALL_DATA} ${WRKSRC}/tex-site.el.dist ${EGDIR}
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/auctex
	for f in auc-old.el bib-cite.el font-latex.el hilit-LaTeX.el	   \
	latex.el lpath.el multi-prompt.el tex-buf.el tex-info.el tex-jp.el \
	tex.el texmathp.el; do						   \
	${INSTALL_DATA} ${WRKSRC}/$$f* ${EMACS_LISPPREFIX}/auctex; 	   \
	done
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/auctex/style
	${INSTALL_DATA} ${WRKSRC}/style/*.el* ${EMACS_LISPPREFIX}/auctex/style
	${INSTALL_DATA} ${WRKSRC}/doc/auctex* ${PREFIX}/${INFODIR}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
