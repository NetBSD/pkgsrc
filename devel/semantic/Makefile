# $NetBSD: Makefile,v 1.14 2005/06/16 06:57:48 jlam Exp $
#

DISTNAME=	semantic-1.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	cjones@NetBSD.org
HOMEPAGE=	http://cedet.sourceforge.net/semantic.shtml
COMMENT=	Lexer, parser-generator, and parser written for Emacs

DEPENDS+=	speedbar>=0.13:../../editors/speedbar
DEPENDS+=	eieio>=0.17:../../lang/eieio

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
EMACS=			emacs
.else
EMACS=			xemacs
.endif

BUILD_ENV+=	EMACS=${EMACS}

NO_CONFIGURE=	# set
USE_TOOLS+=	gmake

INFO_FILES=	semantic.info
OTHER_INFO=	semantic.info-1 semantic.info-2

# XXX cd ${WRKSRC}; ${MAKE} -V semantic_LISP
SRCS=	semantic.el semantic-util.el semantic-bnf.el semantic-ctxt.el
# XXX cd ${WRKSRC}; ${MAKE} -V Languages_LISP
SRCS+=	semantic-c.el semantic-el.el semantic-java.el semantic-make.el \
	semantic-scm.el semantic-texi.el
# XXX cd ${WRKSRC}; ${MAKE} -V tools_LISP
SRCS+=	semantic-imenu.el semantic-sb.el working.el semanticdb.el document.el \
	document-vars.el sformat.el semantic-chart.el semantic-util-modes.el \
	semantic-analyze.el semantic-ia.el semantic-cb.el semantic-ia-sb.el
# XXX cd ${WRKSRC}; ${MAKE} -V senator_LISP
SRCS+=	senator.el

# XXX cd ${WRKSRC}; ${MAKE} -V init_LISP
AUXFILES=	semantic-load.el
# XXX cd ${WRKSRC}; ${MAKE} -V aux_AUX
AUXFILES+=	c.bnf make.bnf java.bnf scheme.bnf

INSTALLATION_DIRS=	${INFO_DIR}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/semantic
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${EMACS_LISPPREFIX}/semantic
	cd ${WRKSRC} && ${INSTALL_DATA} ${AUXFILES} ${EMACS_LISPPREFIX}/semantic
	cd ${WRKSRC} && ${INSTALL_DATA} ${INFO_FILES} ${OTHER_INFO}	\
			${PREFIX}/${INFO_DIR}

.include "../../mk/bsd.pkg.mk"
