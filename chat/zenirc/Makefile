# $NetBSD: Makefile,v 1.16 2018/01/13 23:18:27 rillig Exp $
#

DISTNAME=	zenirc-2.112
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.splode.com/pub/zenirc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.splode.com/~friedman/software/emacs-lisp/zenirc/
COMMENT=	IRC client for Emacs

GNU_CONFIGURE=	YES
CONFIGURE_HAS_MANDIR=	NO

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "xemacs"
MAKE_FLAGS+=	EMACS=xemacs
.endif
MAKE_FLAGS+=	elispdir=${DESTDIR}${EMACS_LISPPREFIX}/zenirc

.include "../../mk/bsd.pkg.mk"
