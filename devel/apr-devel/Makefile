# $NetBSD: Makefile,v 1.3 2002/08/03 15:49:22 hubertf Exp $

DISTNAME=	apr_20020725223645
PKGNAME=	apr-0.20020725223645
CATEGORIES=	devel
MASTER_SITES=	http://www.apache.org/dist/apr/not-released/
DISTFILES=	apr_20020725223645.tar.gz apr-util_20020725223700.tar.gz

MAINTAINER=	joelw@unix.se
HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Run-time, a system portability layer

DEPENDS=	autoconf>=2.50:../../devel/autoconf-devel
DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

pre-configure:
	(cd ${WRKDIR}/apr && ./buildconf)
	(cd ${WRKDIR}/apr-util && ./buildconf)

do-configure:
	(cd ${WRKDIR}/apr && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} \
		--with-devrandom=/dev/urandom \
		)
	(cd ${WRKDIR}/apr-util && ${SETENV} ${CONFIGURE_ENV} ./configure --prefix=${PREFIX} --with-apr=../apr --with-expat=${LOCALBASE})

do-build:
	(cd ${WRKDIR}/apr && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS})
	(cd ${WRKDIR}/apr-util && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS})

do-install:
	(cd ${WRKDIR}/apr && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET})
	(cd ${WRKDIR}/apr-util && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET})

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
