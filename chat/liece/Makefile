# $NetBSD: Makefile,v 1.7 2004/01/22 07:49:20 grant Exp $

DISTNAME=	liece-1.4.10
CATEGORIES=	chat
MASTER_SITES=	http://www.unixuser.org/~ueno/liece/dist/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.unixuser.org/~ueno/liece/
COMMENT=	IRC client for Emacs/XEmacs

DEPENDS=	${PKGNAME_PREFIX}apel>=10.3:../../devel/apel

.include "../../mk/emacs.mk"

HAS_CONFIGURE=	# defined
USE_GNU_TOOLS+=	make
.if ${EMACS_FLAVOR} == "emacs"
CONFIGURE_ARGS+=--with-emacs=${EMACS_BIN}
.else
CONFIGURE_ARGS+=--with-xemacs=${EMACS_BIN}
.endif
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}

INFO_FILES=	liece.info

.include "../../mk/bsd.pkg.mk"
