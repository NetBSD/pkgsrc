# $NetBSD: Makefile,v 1.1.1.1 2008/03/02 12:26:08 obache Exp $
#

DISTNAME=	mell-1.0.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://taiyaki.org/elisp/mell/src/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/elisp/mell/
COMMENT=	M Emacs Lisp Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-emacs-sitelispdir=${EMACS_LISPPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
