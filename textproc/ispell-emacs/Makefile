# $NetBSD: Makefile,v 1.2 2003/03/29 12:42:38 jmmv Exp $
#

DISTNAME=	ispell.el
PKGNAME=	ispell-emacs-3.6
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	ftp://kdstevens.com/pub/stevens/
EXTRACT_SUFX=	.gz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://kdstevens.com/~stevens/ispell-page.html
COMMENT=	Emacs interface for ispell spell checker

DEPENDS=	ispell-base-[0-9]*:../../textproc/ispell-base

DIST_SUBDIR=	${PKGNAME_NOREV}

NO_CONFIGURE=	#
NO_BUILD=	#

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/ispell
	${INSTALL_DATA} ${WRKSRC}/ispell.el ${EMACS_LISPPREFIX}/ispell

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
