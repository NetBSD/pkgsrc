# $NetBSD: Makefile,v 1.7 2000/10/11 15:07:47 hubertf Exp $

DISTNAME=		pchar-1.2
CATEGORIES=		net
MASTER_SITES=		http://www.employees.org/~bmah/Software/pchar/

MAINTAINER=		soren@netbsd.org
HOMEPAGE=		http://www.employees.org/~bmah/Software/pchar/

GNU_CONFIGURE=		yes

BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--with-ipv6
.endif

.if ${OPSYS} == "NetBSD"
DEPENDS+=		ucd-snmp-*:../../net/ucd-snmp
CONFIGURE_ARGS+=	--with-snmp=${PREFIX}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pchar.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
