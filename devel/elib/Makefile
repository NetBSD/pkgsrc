# $NetBSD: Makefile,v 1.1.1.1 2001/06/08 21:29:13 cjones Exp $
#

DISTNAME=	elib-1.0
CATEGORIES=	devel
MASTER_SITES=	http://jde.sunsite.dk/

MAINTAINER=	cjones@netbsd.org
COMMENT=	Library of utility functions for Emacs

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	 	xemacs-*:../../editors/xemacs
EMACS=			xemacs
LISPDIR=		lib/xemacs/xemacs-packages/lisp/elib
.else
DEPENDS+=	 	emacs-*:../../editors/emacs
EMACS=			emacs
LISPDIR=		share/emacs/site-lisp/elib
.endif

BUILD_ENV+=	EMACS=${EMACS}
PLIST_SUBST+=	LISPDIR=${LISPDIR}

NO_CONFIGURE=	# set
USE_GMAKE=	# set

INFO_FILES=	elib.info

SRCS=	stack-f.el stack-m.el queue-f.el queue-m.el elib-node.el	\
	bintree.el avltree.el string.el read.el cookie.el dll.el	\
	dll-debug.el

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${PREFIX}/${LISPDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${INFO_FILES} ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
