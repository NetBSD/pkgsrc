# $NetBSD: Makefile,v 1.9 2003/06/02 01:17:34 jschauma Exp $
#

DISTNAME=		pax-19980903
PKGNAME=		pax-19990423
WRKSRC=			${WRKDIR}/pax
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Standard POSIX portable archiver

PREFIX=			/
MAKE_ENV+=		BINDIR=/bin MANDIR=/usr/share/man
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done
MANCOMPRESSED_IF_MANZ=	yes

post-extract:
	${GREP} -v __RCSID ${FILESDIR}/pwcache.c >${WRKSRC}/pwcache.c
	${CP} ${FILESDIR}/pwcache.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
