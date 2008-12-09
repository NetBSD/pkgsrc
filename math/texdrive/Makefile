# $NetBSD: Makefile,v 1.1.1.1 2008/12/09 12:19:59 wiz Exp $
#

DISTNAME=	texdrive
PKGNAME=	texdrive-0.0.20081126.171834
CATEGORIES=	math
MASTER_SITES=	http://www.djcbsoftware.nl/code/texdrive/
EXTRACT_SUFX=	.el

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.djcbsoftware.nl/code/texdrive/
COMMENT=	Emacs mode for creating inline formulae for HTML

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
MESSAGE_SUBST+=	LISPDIR=${EMACS_LISPPREFIX:Q}

do-build:
	cd ${WRKSRC} && ${EMACS_BIN} -batch -f batch-byte-compile texdrive.el

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}
	${INSTALL_DATA} ${WRKSRC}/texdrive.* ${DESTDIR}${EMACS_LISPPREFIX}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
