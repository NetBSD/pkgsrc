# $NetBSD: Makefile,v 1.11 2004/01/18 18:55:24 epg Exp $

PKGNAME=	apr-${APR_VERSION}.${APACHE_VERSION}
PKGREVISION=	1
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

APR_CONFIGURE_ARGS= \
		--prefix=${PREFIX} \
		--with-devrandom=/dev/urandom \
		--with-installbuilddir=${PREFIX}/libexec/apr

APU_CONFIGURE_ARGS= \
		--prefix=${PREFIX} \
		--with-apr=${WRKSRC}/apr \
		--with-expat=${BUILDLINK_PREFIX.expat}

.include "../../mk/bsd.prefs.mk"
.if ${APR_USE_DB4} == "YES"
APU_CONFIGURE_ARGS+=\
	--with-berkeley-db=${BUILDLINK_PREFIX.db4}/include:${LOCALBASE}
.else
APU_CONFIGURE_ARGS+=	--with-dbm=sdbm
.endif

do-configure:
	@cd ${WRKSRC}/apr && ${SETENV} ${CONFIGURE_ENV} ./configure \
		${APR_CONFIGURE_ARGS}
	@cd ${WRKSRC}/apr-util && ${SETENV} ${CONFIGURE_ENV} ./configure \
		${APU_CONFIGURE_ARGS}

post-install:
	${RM} ${PREFIX}/libexec/apr/libtool
	${INSTALL_SCRIPT} ${LIBTOOL} ${PREFIX}/libexec/apr/libtool

.include "../../www/apache2/Makefile.common"

.if ${APR_USE_DB4} == "YES"
.include "../../databases/db4/buildlink2.mk"
.endif

.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
