# $NetBSD: Makefile,v 1.5 2000/06/15 11:32:20 hubertf Exp $

DISTNAME=		pchar-1.2
CATEGORIES=		net
MASTER_SITES=		http://www.employees.org/~bmah/Software/pchar/

MAINTAINER=		soren@netbsd.org
HOMEPAGE=		http://www.ca.sandia.gov/~bmah/Software/pchar/

GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--with-snmp=${PREFIX}

BUILD_DEFS+=	USE_INET6
.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--with-ipv6
.endif

DEPENDS+=		ucd-snmp-*:../../net/ucd-snmp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pchar.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
