# $NetBSD: Makefile,v 1.1.1.1 1998/11/23 21:39:41 tv Exp $
#

DISTNAME=	bind-4.9.7-REL
PKGNAME=	bind-4.9.7
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/4.9.7/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.isc.org/

NO_WRKSUBDIR=	yes

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
