# $NetBSD: Makefile,v 1.2 1999/04/23 13:37:24 hubertf Exp $
#

DISTNAME=		pax-19990423
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

PREFIX=			/
WRKSRC=			${WRKDIR}/pax
MAKE_ENV+=		BINDIR=/bin MANDIR=/usr/share/man
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=		yes
.endif

post-extract: 
	${CP} ${FILESDIR}/pwcache.c ${WRKSRC}
	${CP} ${FILESDIR}/pwcache.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
