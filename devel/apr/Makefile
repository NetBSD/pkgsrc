# $NetBSD: Makefile,v 1.1.1.1 2003/05/25 08:55:18 epg Exp $

PKGNAME=	apr-${APR_VERSION}.${APACHE_VERSION}
CATEGORIES=	devel

HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Runtime

CONFLICTS=		apache2<2.0.45

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/apr/libtool

WRKSRC=			${WRKDIR}/${DISTNAME}/srclib
BUILD_DIRS=		${WRKSRC}/apr ${WRKSRC}/apr-util

do-configure:
	@cd ${WRKSRC}/apr && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} \
		--with-devrandom=/dev/urandom \
		--with-installbuilddir=${PREFIX}/libexec/apr
	@cd ${WRKSRC}/apr-util && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} \
		--with-apr=${WRKSRC}/apr \
		--with-dbm=sdbm \
		--with-expat=${BUILDLINK_PREFIX.expat}

post-install:
	${RM} ${PREFIX}/libexec/apr/libtool
	${INSTALL_SCRIPT} ${LIBTOOL} ${PREFIX}/libexec/apr/libtool

.include "../../www/apache2/Makefile.common"

.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
