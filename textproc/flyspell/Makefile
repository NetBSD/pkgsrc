# $NetBSD: Makefile,v 1.15 2006/02/05 23:11:01 joerg Exp $
#

DISTNAME=	flyspell-1.7k.el
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME:S/.el//}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www-sop.inria.fr/mimosa/personnel/Manuel.Serrano/flyspell/
EXTRACT_SUFX=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www-sop.inria.fr/mimosa/personnel/Manuel.Serrano/flyspell/flyspell.html
COMMENT=	Emacs/Xemacs on-the-fly spell checker

DEPENDS+=	${EMACS_PKGNAME_PREFIX}ispell-emacs-[0-9]*:../../textproc/ispell-emacs

EXTRACT_ONLY=	# None

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	YES
NO_BUILD=	YES

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/flyspell
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${EMACS_LISPPREFIX}/flyspell/flyspell.el

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
