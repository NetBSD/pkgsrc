# $NetBSD: Makefile,v 1.16 2004/01/20 12:22:18 agc Exp $
#

DISTNAME=	bind-4.9.11-REL
PKGNAME=	bind-4.9.11
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/4.9.11/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.isc.org/
COMMENT=	The BIND name server, version 4, as an alternative to BIND 8

WRKSRC=		${WRKDIR}

.if !exists(/usr/sbin/named-bootconf)
PKG_FAIL_REASON= "${PKGNAME} is intended for NetBSD 1.4 or higher"
.endif

post-extract:
	@${RM} -f ${WRKSRC}/compat/include/sys/cdefs.h

do-build:
	@cd ${WRKSRC}/res && ${MAKE} CDEBUG="${CFLAGS}"
	@cd ${WRKSRC}/named && ${MAKE} CDEBUG="${CFLAGS}" PATH_XFER="${PREFIX}/libexec/named4-xfer" COMPLIB=
	cd ${WRKSRC}/named && \
		${SED} -e 's,/usr/sbin,${PREFIX}/sbin,' -e 's,named ,named4 ,' ndc >ndc4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/named/named ${PREFIX}/sbin/named4
	${INSTALL_PROGRAM} ${WRKSRC}/named/named-xfer ${PREFIX}/libexec/named4-xfer
	${INSTALL_SCRIPT} ${WRKSRC}/named/ndc4 ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/named.8 ${PREFIX}/man/man8/named4.8

.include "../../mk/bsd.pkg.mk"
