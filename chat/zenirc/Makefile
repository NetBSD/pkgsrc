# $NetBSD: Makefile,v 1.6 2003/06/27 16:10:01 seb Exp $
#

DISTNAME=	zenirc-2.112
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.splode.com/pub/zenirc/

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.splode.com/~friedman/software/emacs-lisp/zenirc/
COMMENT=	IRC client for Emacs

GNU_CONFIGURE=	YES

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "xemacs"
MAKE_FLAGS+=	EMACS=xemacs
.endif
MAKE_FLAGS+=	elispdir=${EMACS_LISPPREFIX}/zenirc

.include "../../mk/bsd.pkg.mk"
