# $NetBSD: Makefile,v 1.8 2003/12/03 14:57:05 epg Exp $

PKGNAME=	apr-${APR_VERSION}.${APACHE_VERSION}
CATEGORIES=	devel

HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Runtime

# Don't bump this when apache upgrades; it is only apache2-2.0.45 and
# under that includes its own apr.  apr was split out in 2.0.45nb1.
CONFLICTS=		apache2<=2.0.45

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/apr/libtool

WRKSRC=			${WRKDIR}/${DISTNAME}/srclib
BUILD_DIRS=		${WRKSRC}/apr ${WRKSRC}/apr-util

CONFIGURE_ENV+=		CFLAGS="${CFLAGS}" LIBS="${LDFLAGS}"

pre-configure:
.for f in apr/config.layout apr-util/config.layout
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/$f > ${WRKSRC}/$f.new
	${MV} ${WRKSRC}/$f.new ${WRKSRC}/$f
.endfor
.undef f

do-configure:
	@cd ${WRKSRC}/apr && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} \
		--with-devrandom=/dev/urandom \
		--with-installbuilddir=${PREFIX}/libexec/apr
	@cd ${WRKSRC}/apr-util && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${PREFIX} \
		--with-apr=${WRKSRC}/apr \
		--with-berkeley-db=${BUILDLINK_PREFIX.db4}/include:${LOCALBASE} \
		--with-expat=${BUILDLINK_PREFIX.expat}

post-install:
	${RM} ${PREFIX}/libexec/apr/libtool
	${INSTALL_SCRIPT} ${LIBTOOL} ${PREFIX}/libexec/apr/libtool

.include "../../www/apache2/Makefile.common"

.include "../../databases/db4/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
