#
# $NetBSD: Makefile,v 1.4 2000/11/10 07:38:22 itojun Exp $
#
# FreeBSD Id: Makefile,v 1.12 1999/06/28 21:25:07 billf Exp
#

DISTNAME=	bind
PKGNAME=	bind-8.2.2p7
WRKSRC=		${WRKDIR}/src
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/8.2.2-P7/
DISTFILES=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/

Y2K=		http://www.isc.org/ISC/y2k.html

DIST_SUBDIR=	bind/8.2.2-P7
EXTRACT_ONLY=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz

post-build:
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} clean all)

post-install:
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	${MKDIR} ${PREFIX}/share/doc/bind8
	${INSTALL_DATA} ${WRKDIR}/doc/html/* ${PREFIX}/share/doc/bind8

.include "../../mk/bsd.pkg.mk"
