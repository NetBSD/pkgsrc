# $NetBSD: Makefile,v 1.21 2004/09/25 23:41:26 epg Exp $

PKGNAME=	apr-${APR_VERSION}.${APACHE_VERSION}
CATEGORIES=	devel

HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Runtime

# Don't bump this when apache upgrades; it is only apache2-2.0.45 and
# under that includes its own apr.  apr was split out in 2.0.45nb1.
CONFLICTS=		apache2<=2.0.45

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

WRKSRC=			${WRKDIR}/${DISTNAME}/srclib
BUILD_DIRS=		${WRKSRC}/apr ${WRKSRC}/apr-util

CONFIGURE_ENV+=		CFLAGS="${CFLAGS}" LIBS="${LDFLAGS}"

LDFLAGS.SunOS+=		-lnsl

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
		--with-expat=${BUILDLINK_PREFIX.expat} \
		--without-gdbm

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		APR_USE_OPENLDAP APR_USE_DB4

.if !empty(APR_USE_DB4:M[Yy][Ee][Ss])
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
	${INSTALL_SCRIPT} ${PKG_LIBTOOL} ${PREFIX}/libexec/apr/libtool
	@${CHMOD} ${SHAREMODE} ${PREFIX}/include/apr-0/*.h
	@${CHMOD} ${BINMODE} ${PREFIX}/include/apr-0
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/include/apr-0/

.include "../../www/apache2/Makefile.common"

.if !empty(APR_USE_DB4:M[Yy][Ee][Ss)
.include "../../databases/db4/buildlink3.mk"
.endif

# Enable OpenLDAP support
.if !empty(APR_USE_OPENLDAP:M[Yy][Ee][Ss])
APU_CONFIGURE_ARGS+=	--with-ldap
APR_CONFIGURE_ARGS+=	--with-ldap
.include "../../databases/openldap/buildlink3.mk"
.endif

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
