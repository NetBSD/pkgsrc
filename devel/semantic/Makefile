# $NetBSD: Makefile,v 1.1.1.1 2001/06/08 21:03:05 cjones Exp $
#

DISTNAME=	semantic-1.3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cedet/}

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://cedet.sourceforge.net/semantic.shtml
COMMENT=	Lexer, parser-generator, and parser written for Emacs

DEPENDS+=	speedbar-0.13a:../../editors/speedbar
DEPENDS+=	eieio-0.16:../../lang/eieio

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	 	xemacs-*:../../editors/xemacs
EMACS=			xemacs
LISPDIR=		lib/xemacs/xemacs-packages/lisp/semantic
.else
DEPENDS+=	 	emacs-*:../../editors/emacs
EMACS=			emacs
LISPDIR=		share/emacs/site-lisp/semantic
.endif

BUILD_ENV+=	EMACS=${EMACS}
PLIST_SUBST+=	LISPDIR=${LISPDIR}

NO_CONFIGURE=	# set
USE_GMAKE=	# set

# XXX The author claims that the info file is broken for current
# makeinfo. Should work with either newer makeinfo or newer semantic.
#INFO_FILES=	semantic.info

SRCS=	semantic-bnf.el semantic.el semantic-util.el document.el	\
	document-vars.el sformat.el semantic-make.el semantic-c.el	\
	semantic-imenu.el semantic-el.el semantic-sb.el working.el	\
	semantic-mode.el
BNFFILES=	c.bnf make.bnf

# XXX broken info
post-extract:
	cd ${WRKSRC} && touch semantic.info

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${BNFFILES} ${PREFIX}/${LISPDIR}
# XXX	cd ${WRKSRC} && ${INSTALL_DATA} ${INFO_FILES} ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
