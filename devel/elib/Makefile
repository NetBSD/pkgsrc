# $NetBSD: Makefile,v 1.4 2002/09/14 02:49:54 uebayasi Exp $
#

DISTNAME=	elib-1.0
CATEGORIES=	devel
MASTER_SITES=	http://jde.sunsite.dk/

MAINTAINER=	cjones@netbsd.org
COMMENT=	Library of utility functions for Emacs

.include "../../mk/bsd.prefs.mk"

.include "../../mk/emacs.mk"

BUILD_ENV+=	EMACS=${EMACS_FLAVOR}

MAKEFLAGS+=	EMACS=${EMACS_FLAVOR}

NO_CONFIGURE=	# set
USE_GMAKE=	# set

INFO_FILES=	elib.info

SRCS=	stack-f.el stack-m.el queue-f.el queue-m.el elib-node.el	\
	bintree.el avltree.el string.el read.el cookie.el dll.el	\
	dll-debug.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/elib
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${EMACS_LISPPREFIX}/elib
	cd ${WRKSRC} && ${INSTALL_DATA} ${INFO_FILES} ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
