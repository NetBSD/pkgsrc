# $NetBSD: Makefile,v 1.9 2001/02/17 18:19:26 wiz Exp $

DISTNAME=		pchar-1.3
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
#.if ${OPSYS} == "NetBSD"
#DEPENDS+=		ucd-snmp-*:../../net/ucd-snmp
#CONFIGURE_ARGS+=	--with-snmp=${PREFIX}
#.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pchar.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
