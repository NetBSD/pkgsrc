# $NetBSD: Makefile,v 1.13 2002/02/17 21:12:07 tron Exp $

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
.include "..//ucd-snmp/buildlink.mk"

CONFIGURE_ARGS+=	--with-snmp=${BUILDLINK_DIR}
LIBS+=			-lsnmp -lssl -lcrypto
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pchar.8 ${PREFIX}/man/man8

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
