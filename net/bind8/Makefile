#
# $NetBSD: Makefile,v 1.1.1.1 1999/11/12 18:23:52 rh Exp $
#
# FreeBSD Id: Makefile,v 1.12 1999/06/28 21:25:07 billf Exp
#
# Adapted for NetBSD by Greg A. Woods <woods@planix.com>
# July 28, 1999
#
# Upgraged to 8.2.2-P3 by Greg A. Woods <woods@planix.com>
# November 11, 1999
#

DISTNAME=	bind
PKGNAME=	bind-8.2.2p3
WRKSRC=		${WRKDIR}/src
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/8.2.2-P3/
DISTFILES=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz patch4

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/

Y2K=		http://www.isc.org/ISC/y2k.html

DIST_SUBDIR=	bind/8.2.2-P3
EXTRACT_ONLY=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz

PATCH_ARGS=	-d ${WRKDIR}

pre-patch:
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@(cd ${_DISTDIR}; \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying distribution patch 'patch4'" ; \
		fi; \
		${PATCH} -d ${WRKDIR}/src/bin/named-xfer -p1 < 'patch4')

post-build:
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} clean all)

post-install:
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	${MKDIR} ${PREFIX}/share/doc/bind8
	${INSTALL_DATA} ${WRKDIR}/doc/html/* ${PREFIX}/share/doc/bind8

.include "../../mk/bsd.pkg.mk"
