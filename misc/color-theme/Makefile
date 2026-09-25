# $NetBSD: Makefile,v 1.7 2026/09/25 09:48:11 wiz Exp $

DISTNAME=	color-theme-6.6.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	https://download.savannah.gnu.org/releases/color-theme/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://www.nongnu.org/color-theme/
COMMENT=	Emacs-lisp mode for skinning your emacs
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

MAKE_FLAGS+=	EMACS=${EMACS_BIN}
MAKE_FLAGS+=	ELISPDIR=${DESTDIR}${EMACS_LISPPREFIX}/color-theme

EMACS_VERSIONS_INCOMPATIBLE=	xemacs214 xemacs214nox xemacs215 xemacs215nox

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
