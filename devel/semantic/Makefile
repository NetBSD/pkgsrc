# $NetBSD: Makefile,v 1.5 2002/02/18 15:14:15 seb Exp $
#

DISTNAME=	semantic-1.4beta5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://cedet.sourceforge.net/semantic.shtml
COMMENT=	Lexer, parser-generator, and parser written for Emacs

DEPENDS+=	speedbar-0.13a:../../editors/speedbar
DEPENDS+=	eieio-0.16:../../lang/eieio

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	 	xemacs-[0-9]*:../../editors/xemacs
EMACS=			xemacs
LISPDIR=		lib/xemacs/xemacs-packages/lisp/semantic
.else
DEPENDS+=	 	emacs-[0-9]*:../../editors/emacs
EMACS=			emacs
LISPDIR=		share/emacs/site-lisp/semantic
.endif

BUILD_ENV+=	EMACS=${EMACS}
PLIST_SUBST+=	LISPDIR=${LISPDIR}

NO_CONFIGURE=	# set
USE_GMAKE=	# set

INFO_FILES=	semantic.info
OTHER_INFO=	semantic.info-1 semantic.info-2

SRCS=	semantic.el semantic-util.el semantic-bnf.el semantic-ctxt.el \
	semantic-c.el semantic-el.el semantic-java.el semantic-make.el \
	semantic-scm.el semantic-texi.el semantic-imenu.el \
	semantic-sb.el working.el semanticdb.el document.el \
	document-vars.el sformat.el senator.el
AUXFILES=	c.bnf make.bnf java.bnf scheme.bnf semantic-load.el

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${AUXFILES} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${INFO_FILES} ${OTHER_INFO}	\
			${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
