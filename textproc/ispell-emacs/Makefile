# $NetBSD: Makefile,v 1.10 2008/10/11 09:31:58 uebayasi Exp $
#

DISTNAME=	ispell.el
PKGNAME=	${EMACS_PKGNAME_PREFIX}ispell-emacs-3.6
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://kdstevens.com/pub/stevens/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eng.utah.edu/~kstevens/ispell-page.html
COMMENT=	Emacs interface for ispell spell checker

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/ispell

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base

DIST_SUBDIR=	${PKGNAME_NOREV:C|^xemacs-||}
WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/ispell.el ${DESTDIR}${EMACS_LISPPREFIX}/ispell

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
