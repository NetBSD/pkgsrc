# $NetBSD: Makefile,v 1.12 2009/08/06 01:44:46 minskim Exp $
#

DISTNAME=	zenirc-2.112
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.splode.com/pub/zenirc/

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.splode.com/~friedman/software/emacs-lisp/zenirc/
COMMENT=	IRC client for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
CONFIGURE_HAS_MANDIR=	NO

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "xemacs"
MAKE_FLAGS+=	EMACS=xemacs
.endif
MAKE_FLAGS+=	elispdir=${DESTDIR:Q}${EMACS_LISPPREFIX:Q}/zenirc

.include "../../mk/bsd.pkg.mk"
