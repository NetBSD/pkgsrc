# $NetBSD: Makefile,v 1.1.1.1 2002/05/04 22:47:23 wiz Exp $

DISTNAME=	leim-${VERSION}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	Libraries of Emacs Input Methods (for emacs21)

DEPENDS+=	emacs-${VERSION}:../emacs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

VERSION=	21.2
WRKSRC=		${WRKDIR}/emacs-21.2/leim

post-extract:
	@${ECHO} '#!/bin/sh' >${WRKSRC}/configure
	@${ECHO} 'cd ..' >>${WRKSRC}/configure
	@${ECHO} 'exec ./configure $$*' >>${WRKSRC}/configure
	@${CHMOD} +x ${WRKSRC}/configure

.include "../../mk/bsd.pkg.mk"
