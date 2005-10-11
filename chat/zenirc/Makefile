# $NetBSD: Makefile,v 1.9 2005/10/11 20:08:44 reed Exp $
#

DISTNAME=	zenirc-2.112
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.splode.com/pub/zenirc/

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.splode.com/~friedman/software/emacs-lisp/zenirc/
COMMENT=	IRC client for Emacs

GNU_CONFIGURE=	YES
CONFIGURE_HAS_MANDIR=	NO

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "xemacs"
MAKE_FLAGS+=	EMACS=xemacs
.endif
MAKE_FLAGS+=	elispdir=${EMACS_LISPPREFIX}/zenirc

.include "../../mk/bsd.pkg.mk"
