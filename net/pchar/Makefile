# $NetBSD: Makefile,v 1.2 1999/11/04 05:57:15 itojun Exp $

DISTNAME=		pchar-1.0
CATEGORIES=		net
MASTER_SITES=		http://www.ca.sandia.gov/~bmah/Software/pchar/

MAINTAINER=		soren@netbsd.org
HOMEPAGE=		http://www.ca.sandia.gov/~bmah/Software/pchar/

GNU_CONFIGURE=		yes

# IPv6 veresion cannot be built at this moment, due to the lack of
# getipnodebyname()
#BUILD_DEFS+=	USE_INET6
#.include "../../mk/bsd.prefs.mk"
#.if defined(USE_INET6) && ${USE_INET6} == YES
#CONFIGURE_ARGS+=	--with-ipv6
#.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin; \
	${INSTALL_MAN} ${WRKSRC}/pchar.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
