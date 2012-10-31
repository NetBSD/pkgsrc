# $NetBSD: Makefile,v 1.4 2012/10/31 11:17:28 asau Exp $
#

DISTNAME=	mell-1.0.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://taiyaki.org/elisp/mell/src/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/elisp/mell/
COMMENT=	M Emacs Lisp Library

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-emacs-sitelispdir=${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
