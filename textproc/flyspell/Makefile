# $NetBSD: Makefile,v 1.5 2004/11/19 18:27:11 wiz Exp $
#

DISTNAME=	flyspell-1.7f.el
PKGNAME=	${DISTNAME:S/.el//}
CATEGORIES=	textproc
MASTER_SITES=	http://www-sop.inria.fr/mimosa/personnel/Manuel.Serrano/flyspell/
EXTRACT_SUFX=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www-sop.inria.fr/mimosa/personnel/Manuel.Serrano/flyspell/flyspell.html
COMMENT=	Emacs/Xemacs on-the-fly spell checker

DEPENDS=	ispell-emacs-[0-9]*:../../textproc/ispell-emacs

EXTRACT_ONLY=	# None

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	#
NO_BUILD=	#

do-extract:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/flyspell
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${EMACS_LISPPREFIX}/flyspell/flyspell.el

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
