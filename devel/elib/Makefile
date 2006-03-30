# $NetBSD: Makefile,v 1.17 2006/03/30 03:31:13 jlam Exp $
#

DISTNAME=	elib-1.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://jde.sunsite.dk/

MAINTAINER=	cjones@NetBSD.org
COMMENT=	Library of utility functions for Emacs

CONFLICTS+=	emacs20-elib-[0-9]*

.include "../../mk/emacs.mk"

BUILD_ENV+=	EMACS=${EMACS_FLAVOR}
MAKEFLAGS+=	EMACS=${EMACS_FLAVOR:Q}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake makeinfo

INFO_FILES=	# PLIST

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/elib ${EMACS_INFOPREFIX}

SRCS=	stack-f.el stack-m.el queue-f.el queue-m.el elib-node.el	\
	bintree.el avltree.el string.el read.el cookie.el dll.el	\
	dll-debug.el

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/elib
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} 	\
			${EMACS_LISPPREFIX}/elib
	cd ${WRKSRC} && ${INSTALL_DATA} elib.info* ${EMACS_INFOPREFIX}

.include "../../mk/bsd.pkg.mk"
