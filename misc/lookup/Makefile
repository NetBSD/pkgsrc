# $NetBSD: Makefile,v 1.14 2007/02/20 12:47:12 uebayasi Exp $
#

DISTNAME=	lookup-1.4.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://openlab.jp/edict/lookup/dist/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.jp/edict/lookup/index.html.ja
COMMENT=	Electric dictionary agent for Emacs

DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel>=10:../../devel/apel
DEPENDS+=	${EMACS_PKGNAME_PREFIX}eblook>=1.4:../../textproc/eblook

EMACS_VERSIONS_ACCEPTED=	emacs22 emacs22nox emacs21 emacs21nox emacs20 xemacs214 xemacs215

GNU_CONFIGURE=	YES
MAKEFLAGS+=	lispdir=${EMACS_LISPPREFIX}/lookup
INFO_FILES=	# PLIST

CONFIGURE_ARGS+=${EMACS_FLAVOR}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
