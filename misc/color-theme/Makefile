# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:02 rillig Exp $
#

DISTNAME=	color-theme-6.6.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://download.savannah.gnu.org/releases/${PKGBASE}/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://www.nongnu.org/color-theme/
COMMENT=	Emacs-lisp mode for skinning your emacs
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

MAKE_FLAGS+=	EMACS=${EMACS_BIN}
MAKE_FLAGS+=	ELISPDIR=${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
