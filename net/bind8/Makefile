#
# $NetBSD: Makefile,v 1.9 2001/12/24 14:10:54 abs Exp $
#
# FreeBSD Id: Makefile,v 1.12 1999/06/28 21:25:07 billf Exp
#

DISTNAME=	bind
PKGNAME=	bind-8.2.4
PKGREVISION=	1
WRKSRC=		${WRKDIR}/src
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/8.2.4/
DISTFILES=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/
COMMENT=	The Berkeley Internet Name Daemon, an implementation of DNS

Y2K=		http://www.isc.org/ISC/y2k.html

DIST_SUBDIR=	bind/8.2.4
EXTRACT_ONLY=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PLIST_SRC=		${PKGDIR}/PLIST-Linux
.endif

post-build:
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} clean all)

pre-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/named.sh > ${WRKDIR}/named.sh

post-install:
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bind8
	(cd ${WRKDIR}/doc/html/; tar Bpcf - .) | (cd ${PREFIX}/share/doc/bind8; tar Bpxf -)
	${INSTALL_SCRIPT} ${WRKDIR}/named.sh ${PREFIX}/etc/rc.d/named

.include "../../mk/bsd.pkg.mk"
.include "../../mk/bsd.pkg.install.mk"
