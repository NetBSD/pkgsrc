# $NetBSD: Makefile,v 1.6 2003/05/04 21:42:52 seb Exp $
#

DISTNAME=	elib-1.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://jde.sunsite.dk/

MAINTAINER=	cjones@netbsd.org
COMMENT=	Library of utility functions for Emacs

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
	cd ${WRKSRC} && ${INSTALL_DATA} elib.info* ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
