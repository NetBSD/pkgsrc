# $NetBSD: Makefile,v 1.25.2.1 2006/10/31 10:18:19 ghen Exp $

PKGNAME=		postgresql74-lib-${BASE_VERS}
SVR4_PKGNAME=		pstgl
COMMENT=		PostgreSQL database headers and libraries

.include "../../databases/postgresql74/Makefile.common"

USE_TOOLS+=		tar
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

.include "../../mk/bsd.prefs.mk"

BUILD_DIRS+=		src/include
BUILD_DIRS+=		src/interfaces
BUILD_DIRS+=		src/bin/pg_config

# without this the Darwin build fails
# (-bundle_loader related)
BUILD_DIRS+=		src/backend

BUILD_DIRS+=		src/pl

# As told by Josh Berkus
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native" \
	&& ${OPSYS} != "NetBSD" && ${OPSYS} != "DragonFly"
CONFIGURE_ARGS+=	--enable-thread-safety
.endif

# handle additional headers installed by hierarchical queries patch
.if defined(PGSQL_USE_HIER) && !empty(PGSQL_USE_HIER:M[yY][eE][sS])
PLIST_SUBST+=		PG_HIER=
.else
PLIST_SUBST+=		PG_HIER="@comment "
.endif

post-wrapper:
#
# Avoid conflict between "${LOCALBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
#
.if (${OPSYS} == "SunOS")
	touch ${BUILDLINK_DIR}/include/crypt.h
.endif

do-install:
	cd ${WRKSRC} && env ${MAKE_ENV} ${MAKE_PROGRAM} -C src/include install
	cd ${WRKSRC} && env ${MAKE_ENV} ${MAKE_PROGRAM} -C src/interfaces install
	cd ${WRKSRC} && env ${MAKE_ENV} ${MAKE_PROGRAM} -C src/bin/pg_config install
	cd ${WRKSRC} && env ${MAKE_ENV} ${MAKE_PROGRAM} -C src/pl install
	cd ${WRKSRC}/src/include && env ${MAKE_ENV} \
		${MAKE_PROGRAM} install-all-headers

post-install:
	egrep -v "^#" ${FILESDIR}/man.lib > ${WRKDIR}/man_tar
	cd ${PREFIX}/${PKGMANDIR} && tar -zxm -T ${WRKDIR}/man_tar  		\
		-f ${WRKSRC}/doc/man.tar.gz

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
