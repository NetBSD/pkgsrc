# $NetBSD: Makefile,v 1.10 2003/04/12 14:15:07 wiz Exp $

DISTNAME=	leim-${VERSION}
WRKSRC=		${WRKDIR}/emacs-${VERSION}/leim
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods (for emacs21)

DEPENDS+=	emacs-${VERSION}:../emacs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

VERSION=	21.3

post-extract:
	@${ECHO} '#!/bin/sh' >${WRKSRC}/configure
	@${ECHO} 'cd ..' >>${WRKSRC}/configure
	@${ECHO} 'exec ./configure $$*' >>${WRKSRC}/configure
	@${CHMOD} +x ${WRKSRC}/configure

.include "../../mk/bsd.prefs.mk"

post-install:
	@${CHOWN} -R ${ROOT_USER} ${PREFIX}/share/emacs/${VERSION}/leim

.include "../../mk/bsd.pkg.mk"
