# $NetBSD: Makefile,v 1.16 2004/05/08 15:15:07 uebayasi Exp $

DISTNAME=	leim-${VERSION}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods (for emacs21)

WRKSRC=		${WRKDIR}/emacs-${VERSION}/leim
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

VERSION=	21.3

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
