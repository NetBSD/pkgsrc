# $NetBSD: Makefile,v 1.19 2003/11/12 03:39:41 jschauma Exp $

DISTNAME=		pchar-1.4
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.employees.org/~bmah/Software/pchar/

MAINTAINER=		soren@NetBSD.org
HOMEPAGE=		http://www.employees.org/~bmah/Software/pchar/
COMMENT=		Tool for measuring Internet path characteristics

GNU_CONFIGURE=		yes

USE_BUILDLINK2=		yes
BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--with-ipv6
.endif

.if ${OPSYS} == "NetBSD"
.include "../ucd-snmp/buildlink2.mk"

CONFIGURE_ARGS+=	--with-snmp=${BUILDLINK_PREFIX.ucd-snmp}
LIBS+=			-lsnmp -lcrypto
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pchar ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pchar.8 ${PREFIX}/man/man8

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
