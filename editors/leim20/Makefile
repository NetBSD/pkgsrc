# $NetBSD: Makefile,v 1.6 2004/04/05 13:47:55 wiz Exp $

DISTNAME=	leim-${VERSION}
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods

DEPENDS+=	emacs-${VERSION}nb3:../emacs20

WRKSRC=		${WRKDIR}/emacs-20.7/leim
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

VERSION=	20.7

post-extract:
	@${ECHO} '#!/bin/sh' >${WRKSRC}/configure
	@${ECHO} 'cd ..' >>${WRKSRC}/configure
	@${ECHO} 'exec ./configure $$*' >>${WRKSRC}/configure
	@${CHMOD} +x ${WRKSRC}/configure

.include "../../mk/bsd.prefs.mk"

post-install:
	@${CHOWN} -R ${ROOT_USER} ${PREFIX}/share/emacs/20.7/leim

.include "../../mk/bsd.pkg.mk"
