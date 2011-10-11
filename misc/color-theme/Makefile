# $NetBSD: Makefile,v 1.1.1.1 2011/10/11 19:52:48 minskim Exp $
#

DISTNAME=	color-theme-6.6.0
CATEGORIES=	misc
MASTER_SITES=	http://download.savannah.gnu.org/releases/${PKGBASE}/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.nongnu.org/color-theme/
COMMENT=	Emacs-lisp mode for skinning your emacs
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

MAKE_FLAGS+=	EMACS=${EMACS_BIN}
MAKE_FLAGS+=	ELISPDIR=${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
