# $NetBSD: Makefile,v 1.6 2005/12/05 20:51:03 rillig Exp $
#

DISTNAME=	ispell.el
PKGNAME=	${EMACS_PKGNAME_PREFIX}ispell-emacs-3.6
CATEGORIES=	textproc
MASTER_SITES=	ftp://kdstevens.com/pub/stevens/
EXTRACT_SUFX=	.gz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://kdstevens.com/~stevens/ispell-page.html
COMMENT=	Emacs interface for ispell spell checker

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base

DIST_SUBDIR=	${PKGNAME_NOREV:C|^xemacs-||}
WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/ispell
	${INSTALL_DATA} ${WRKSRC}/ispell.el ${EMACS_LISPPREFIX}/ispell

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
