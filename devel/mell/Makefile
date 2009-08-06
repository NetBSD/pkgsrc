# $NetBSD: Makefile,v 1.3 2009/08/06 01:44:49 minskim Exp $
#

DISTNAME=	mell-1.0.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://taiyaki.org/elisp/mell/src/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/elisp/mell/
COMMENT=	M Emacs Lisp Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-emacs-sitelispdir=${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
