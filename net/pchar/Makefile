# $NetBSD: Makefile,v 1.23 2004/04/25 08:18:06 snj Exp $

DISTNAME=		pchar-1.4
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		http://www.employees.org/~bmah/Software/pchar/

MAINTAINER=		soren@NetBSD.org
HOMEPAGE=		http://www.employees.org/~bmah/Software/pchar/
COMMENT=		Tool for measuring Internet path characteristics

GNU_CONFIGURE=		yes

USE_BUILDLINK3=		yes
BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--with-ipv6
.endif

.if ${OPSYS} == "NetBSD"
.include "../net-snmp/buildlink3.mk"

CONFIGURE_ARGS+=	--with-snmp=${BUILDLINK_PREFIX.net-snmp}
LIBS+=			-lsnmp -lcrypto -ldes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pchar.8 ${PREFIX}/man/man8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
