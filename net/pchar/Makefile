# $NetBSD: Makefile,v 1.1.1.1 1999/11/04 04:38:10 soren Exp $

DISTNAME=		pchar-1.0
CATEGORIES=		net
MASTER_SITES=		http://www.ca.sandia.gov/~bmah/Software/pchar/

MAINTAINER=		soren@netbsd.org
HOMEPAGE=		http://www.ca.sandia.gov/~bmah/Software/pchar/

GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin; \
	${INSTALL_MAN} ${WRKSRC}/pchar.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
