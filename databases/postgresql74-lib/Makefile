# $NetBSD: Makefile,v 1.25 2006/07/17 17:32:30 joerg Exp $

PKGNAME=		postgresql74-lib-${BASE_VERS}
SVR4_PKGNAME=		pstgl
COMMENT=		PostgreSQL database headers and libraries

.include "../../databases/postgresql74/Makefile.common"

USE_TOOLS+=		tar
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

.include "../../mk/bsd.prefs.mk"

BUILD_DIRS+=		${WRKSRC}/src/include
BUILD_DIRS+=		${WRKSRC}/src/interfaces
BUILD_DIRS+=		${WRKSRC}/src/bin/pg_config

# without this the Darwin build fails
# (-bundle_loader related)
BUILD_DIRS+=		${WRKSRC}/src/backend

BUILD_DIRS+=		${WRKSRC}/src/pl

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
	${TOUCH} ${BUILDLINK_DIR}/include/crypt.h
.endif

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} -C src/include install
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} -C src/interfaces install
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} -C src/bin/pg_config install
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} -C src/pl install
	cd ${WRKSRC}/src/include && ${SETENV} ${MAKE_ENV}	\
		${MAKE_PROGRAM} install-all-headers

post-install:
	${EGREP} -v "^#" ${FILESDIR}/man.lib > ${WRKDIR}/man_tar
	cd ${PREFIX}/${PKGMANDIR} && ${TAR} -zxm -T ${WRKDIR}/man_tar  		\
		-f ${WRKSRC}/doc/man.tar.gz

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
