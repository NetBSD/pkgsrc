# $NetBSD: Makefile,v 1.7 2002/11/25 19:52:43 wiz Exp $

DISTNAME=	apr_20021123173453
PKGNAME=	apr-0.20021123173453
CATEGORIES=	devel
MASTER_SITES=	# http://www.apache.org/dist/apr/not-released/
DISTFILES=	apr_20021123173453.tar.gz apr-util_20021123173519.tar.gz

MAINTAINER=	joelw@unix.se
HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Run-time, a system portability layer

AUTOCONF_REQD=	2.56
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
# Programs using apr-config --apr-libtool will also need USE_LIBTOOL
# That's no reason to make it a dependency, though. -- wiz
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/apr/libtool
WRKSRC=		${WRKDIR}

BUILD_DIRS=	${WRKSRC}/apr ${WRKSRC}/apr-util

pre-configure:
	(cd ${WRKDIR}/apr && ./buildconf)
	(cd ${WRKDIR}/apr-util && ./buildconf)

do-configure:
	(cd ${WRKDIR}/apr && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} \
		--with-devrandom=/dev/urandom \
		)
	(cd ${WRKDIR}/apr-util && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} \
		--with-apr=../apr \
		--with-expat=${BUILDLINK_PREFIX.expat} \
		)

.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
