# $NetBSD: Makefile,v 1.15 2007/10/29 13:08:15 uebayasi Exp $
#

DISTNAME=	lookup-1.4.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://openlab.jp/edict/lookup/dist/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://openlab.jp/edict/lookup/index.html.ja
COMMENT=	Electric dictionary agent for Emacs

DEPENDS+=	eblook>=1.4:../../textproc/eblook

EMACS_VERSIONS_ACCEPTED=	emacs22 emacs22nox emacs21 emacs21nox emacs20 xemacs214 xemacs215

GNU_CONFIGURE=	YES
MAKEFLAGS+=	lispdir=${EMACS_LISPPREFIX}/lookup
INFO_FILES=	# PLIST

CONFIGURE_ARGS+=${EMACS_FLAVOR}

.include "../../mk/emacs.mk"

.include "../../devel/apel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
