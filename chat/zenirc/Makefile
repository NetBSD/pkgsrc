# $NetBSD: Makefile,v 1.4 2002/09/13 10:39:54 uebayasi Exp $
#

DISTNAME=	zenirc-2.112
PKGNAME=	${EMACS_PKGPREFIX}${DISTNAME}
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

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
