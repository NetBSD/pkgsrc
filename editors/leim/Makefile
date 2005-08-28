# $NetBSD: Makefile,v 1.19 2005/08/28 04:25:29 uebayasi Exp $

DISTNAME=	leim-${VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}a${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods (for emacs21)

WRKSRC=		${WRKDIR}/emacs-${VERSION}/leim
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

VERSION=	21.4

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox

post-extract:
	@${ECHO} '#!/bin/sh' >${WRKSRC}/configure
	@${ECHO} 'cd ..' >>${WRKSRC}/configure
	@${ECHO} 'exec ./configure $$*' >>${WRKSRC}/configure
	@${CHMOD} +x ${WRKSRC}/configure

.include "../../mk/bsd.prefs.mk"

post-install:
	@${CHOWN} -R ${ROOT_USER} ${PREFIX}/share/emacs/${VERSION}/leim

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
