# $NetBSD: Makefile,v 1.15 2006/03/04 21:29:31 jlam Exp $

DISTNAME=	leim-${VERSION}
PKGREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods

DEPENDS+=	emacs-${VERSION}{,nb[0-9]*}:../../editors/emacs20

WRKSRC=		${WRKDIR}/emacs-20.7/leim
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

VERSION=	20.7

CONFIG_GUESS_OVERRIDE=	../config.guess
CONFIG_SUB_OVERRIDE=	../config.sub

post-extract:
	@${ECHO} '#!/bin/sh' >${WRKSRC}/configure
	@${ECHO} 'cd ..' >>${WRKSRC}/configure
	@${ECHO} 'exec ./configure $$*' >>${WRKSRC}/configure
	@${CHMOD} +x ${WRKSRC}/configure

.include "../../mk/bsd.prefs.mk"

post-install:
	@${CHOWN} -R ${ROOT_USER} ${PREFIX}/share/emacs/20.7/leim

.include "../../mk/bsd.pkg.mk"
