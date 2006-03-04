# $NetBSD: Makefile,v 1.22 2006/03/04 21:29:31 jlam Exp $

DISTNAME=	leim-${VERSION}
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}a${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods (for emacs21)

WRKSRC=		${WRKDIR}/emacs-${VERSION}/leim
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

VERSION=	21.4

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox

CONFIG_GUESS_OVERRIDE=	../config.guess
CONFIG_SUB_OVERRIDE=	../config.sub

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
