# $NetBSD: Makefile,v 1.3 2003/07/17 22:54:14 grant Exp $
#

DISTNAME=	flyspell.el
PKGNAME=	flyspell-1.7c
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	http://www-sop.inria.fr/mimosa/personnel/Manuel.Serrano/flyspell/
EXTRACT_SUFX=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www-sop.inria.fr/mimosa/personnel/Manuel.Serrano/flyspell/flyspell.html
COMMENT=	Emacs/Xemacs on-the-fly spell checker

DEPENDS=	ispell-emacs-[0-9]*:../../textproc/ispell-emacs

EXTRACT_ONLY=	# None

DIST_SUBDIR=	${PKGNAME_NOREV}

NO_CONFIGURE=	#
NO_BUILD=	#

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/flyspell
	${INSTALL_DATA} ${WRKSRC}/flyspell.el ${EMACS_LISPPREFIX}/flyspell

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
