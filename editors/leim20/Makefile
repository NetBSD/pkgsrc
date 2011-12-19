# $NetBSD: Makefile,v 1.17 2011/12/19 00:52:51 dholland Exp $

DISTNAME=	leim-${VERSION}
PKGREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods

DEPENDS+=	emacs-${VERSION}{,nb[0-9]*}:../../editors/emacs20

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/emacs-20.7
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

VERSION=	20.7

BUILD_DIRS=	leim

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	share/emacs/20.7/leim

post-install:
	@${CHOWN} -R ${ROOT_USER} ${DESTDIR}${PREFIX}/share/emacs/20.7/leim

.include "../../mk/bsd.pkg.mk"
