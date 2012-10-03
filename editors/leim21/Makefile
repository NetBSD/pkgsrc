# $NetBSD: Makefile,v 1.10 2012/10/03 11:43:36 asau Exp $

DISTNAME=	leim-${VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}a${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods (for emacs21)

WRKSRC=		${WRKDIR}/emacs-${VERSION}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

VERSION=	21.4

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox

EMACS21_FILESDIR=	${.CURDIR}/../../editors/emacs21/files

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	share/emacs/${VERSION}/leim

BUILD_DIRS=		leim
post-extract:
	${CP} ${EMACS21_FILESDIR}/dragonfly.h ${WRKSRC}/src/s

.include "../../mk/bsd.prefs.mk"

post-install:
	@${CHOWN} -R ${ROOT_USER} ${DESTDIR}${PREFIX}/share/emacs/${VERSION}/leim

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
