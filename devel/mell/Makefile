# $NetBSD: Makefile,v 1.6 2015/03/15 17:00:30 hiramatsu Exp $
#

DISTNAME=	mell-1.0.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://taiyaki.org/elisp/mell/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://taiyaki.org/elisp/mell/
COMMENT=	M Emacs Lisp Library

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-emacs-sitelispdir=${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
