# $NetBSD: Makefile,v 1.3 2000/01/24 23:23:53 soren Exp $

DISTNAME=		pchar-1.1.1
CATEGORIES=		net
MASTER_SITES=		http://www.ca.sandia.gov/~bmah/Software/pchar/

MAINTAINER=		soren@netbsd.org
HOMEPAGE=		http://www.ca.sandia.gov/~bmah/Software/pchar/

GNU_CONFIGURE=		yes

BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--with-ipv6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pchar.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
