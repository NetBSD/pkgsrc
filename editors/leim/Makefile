# $NetBSD: Makefile,v 1.2 2000/03/10 15:45:35 minoura Exp $

DISTNAME=	leim-${VERSION}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}
DISTFILES=	emacs-${VERSION}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html

DEPENDS+=	emacs-${VERSION}:../emacs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

VERSION=	20.6
WRKSRC=		${WRKDIR}/emacs-20.6/leim

post-extract:
	@${ECHO} '#!/bin/sh' >${WRKSRC}/configure
	@${ECHO} 'cd ..' >>${WRKSRC}/configure
	@${ECHO} 'exec ./configure $$*' >>${WRKSRC}/configure
	@${CHMOD} +x ${WRKSRC}/configure

.include "../../mk/bsd.pkg.mk"
