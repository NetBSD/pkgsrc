#
# $NetBSD: Makefile,v 1.17 2002/12/07 21:35:10 cjep Exp $
#
# FreeBSD Id: Makefile,v 1.12 1999/06/28 21:25:07 billf Exp
#

DISTNAME=	bind
PKGNAME=	bind-${BIND_VERSION}
WRKSRC=		${WRKDIR}/src
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/${BIND_VERSION}/
DISTFILES=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/
COMMENT=	The Berkeley Internet Name Daemon, an implementation of DNS

Y2K=		http://www.isc.org/ISC/y2k.html

BIND_VERSION=	8.3.4
DIST_SUBDIR=	bind/${BIND_VERSION}
EXTRACT_ONLY=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PLIST_SRC=		${PKGDIR}/PLIST-Linux
.endif

.if ${OPSYS} == "SunOS"
MAKEFLAGS+=	MANROFF=cat
MAKEFLAGS+=	INSTALL=${INSTALL}
PLIST_SRC=	${PKGDIR}/PLIST-SunOS
.endif

MAKEFLAGS+=	PREFIX=${PREFIX}

post-build:
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} ${MAKEFILE} clean all)

pre-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/named.sh > ${WRKDIR}/named.sh

post-install:
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind8
	(cd ${WRKDIR}/doc/html/; tar Bpcf - .) | (cd ${PREFIX}/share/doc/bind8; tar Bpxf -)
	${INSTALL_SCRIPT} ${WRKDIR}/named.sh ${PREFIX}/etc/rc.d/named

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
