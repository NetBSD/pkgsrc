#
# $NetBSD: Makefile,v 1.23 2003/12/03 22:14:46 kristerw Exp $
#
# FreeBSD Id: Makefile,v 1.12 1999/06/28 21:25:07 billf Exp
#

DISTNAME=	bind
PKGNAME=	bind-${BIND_VERSION}
WRKSRC=		${WRKDIR}/src
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/${BIND_VERSION}/
DISTFILES=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.isc.org/products/BIND/
COMMENT=	The Berkeley Internet Name Daemon, an implementation of DNS

Y2K=		http://www.isc.org/ISC/y2k.html

BIND_VERSION=	8.4.1
DIST_SUBDIR=	bind/${BIND_VERSION}
EXTRACT_ONLY=	${DISTNAME}-src.tar.gz ${DISTNAME}-doc.tar.gz

USE_PKGINSTALL=	yes
RCD_SCRIPTS=	named

BUILD_DIRS=	${WRKSRC} ${WRKDIR}/doc/man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKEFLAGS+=	MANROFF=cat
MAKEFLAGS+=	INSTALL=${INSTALL}
OWN_DIRS_PERMS=	${PKG_SYSCONFDIR}/ndc.d root other 700
.endif

MAKEFLAGS+=	PREFIX=${PREFIX}

post-extract:
	cd ${WRKDIR}/doc/man &&						\
		${RM} -f *.lst* *~ *.BAK *.CKP *.orig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/bind8
	cd ${WRKDIR}/doc/html && 					\
		${PAX} -rw * ${PREFIX}/share/doc/html/bind8

.include "../../mk/bsd.pkg.mk"
