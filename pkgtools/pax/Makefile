# $NetBSD: Makefile,v 1.6 2001/02/17 17:51:26 wiz Exp $
#

DISTNAME=		pax-19980903
PKGNAME=		pax-19990423
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		NetBSD-current's pax tool

PREFIX=			/
WRKSRC=			${WRKDIR}/pax
MAKE_ENV+=		BINDIR=/bin MANDIR=/usr/share/man
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done
MANCOMPRESSED_IF_MANZ=	yes

post-extract:
	${GREP} -v __RCSID ${FILESDIR}/pwcache.c >${WRKSRC}/pwcache.c
	${CP} ${FILESDIR}/pwcache.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
