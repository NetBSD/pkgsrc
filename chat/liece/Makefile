# $NetBSD: Makefile,v 1.4 2003/06/27 14:36:32 seb Exp $

DISTNAME=	liece-1.4.10
CATEGORIES=	chat
MASTER_SITES=	http://www.unixuser.org/~ueno/liece/dist/

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://www.unixuser.org/~ueno/liece/
COMMENT=	IRC client for Emacs/XEmacs

DEPENDS=	${PKGNAME_PREFIX}apel>=10.3:../../devel/apel

.include "../../mk/emacs.mk"

HAS_CONFIGURE=	# defined
.if ${EMACS_FLAVOR} == "emacs"
CONFIGURE_ARGS+=--with-emacs=${EMACS_BIN}
.else
CONFIGURE_ARGS+=--with-xemacs=${EMACS_BIN}
.endif
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}
USE_GMAKE=	# defined

USE_NEW_TEXINFO=	YES
INFO_FILES=	liece.info

.include "../../mk/bsd.pkg.mk"
