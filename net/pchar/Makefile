# $NetBSD: Makefile,v 1.11 2001/06/13 19:18:24 soren Exp $

DISTNAME=		pchar-1.4
CATEGORIES=		net
MASTER_SITES=		http://www.employees.org/~bmah/Software/pchar/

MAINTAINER=		soren@netbsd.org
HOMEPAGE=		http://www.employees.org/~bmah/Software/pchar/
COMMENT=		Tool for measuring Internet path characteristics

GNU_CONFIGURE=		yes

BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--with-ipv6
.endif

# XXX Not fully integrated
.if ${OPSYS} == "NetBSD"
DEPENDS+=		ucd-snmp-*:../../net/ucd-snmp
CONFIGURE_ARGS+=	--with-snmp=${PREFIX}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pchar.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
