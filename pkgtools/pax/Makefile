# $NetBSD: Makefile,v 1.3 1999/04/23 13:47:44 hubertf Exp $
#

DISTNAME=		pax-19980903
PKGNAME=		pax-19990423
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
	${GREP} -v __RCSID ${FILESDIR}/pwcache.c >${WRKSRC}/pwcache.c
	${CP} ${FILESDIR}/pwcache.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
