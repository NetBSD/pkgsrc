# $NetBSD: Makefile,v 1.2 2005/02/06 13:21:45 taca Exp $

PKGNAME=		postgresql80-lib-${BASE_VERS}
PKGREVISION=		# empty
COMMENT=		PostgreSQL database headers and libraries

.include "../../databases/postgresql80/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl

.include "../../mk/bsd.prefs.mk"

BUILD_DIRS+=		${WRKSRC}/src/include
BUILD_DIRS+=		${WRKSRC}/src/interfaces

# without this the Darwin build fails
# (-bundle_loader related)
BUILD_DIRS+=		${WRKSRC}/src/backend

BUILD_DIRS+=		${WRKSRC}/src/pl

# As told by Josh Berkus
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native" \
	&& ${OPSYS} != "NetBSD"
CONFIGURE_ARGS+=	--enable-thread-safety
.endif

# handle additional headers installed by hierarchical queries patch
.if defined(PGSQL_USE_HIER) && !empty(PGSQL_USE_HIER:M[yY][eE][sS])
PLIST_SUBST+=		PG_HIER=
.else
PLIST_SUBST+=		PG_HIER="@comment "
.endif

post-buildlink:
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
		${MAKE_PROGRAM} -C src/pl install
#	cd ${WRKSRC}/src/include && ${SETENV} ${MAKE_ENV}	\
#		${MAKE_PROGRAM} install-all-headers

post-install:
	${INSTALL_MAN_DIR} ${PG_DIR}/man
	${EGREP} -v "^#" ${FILESDIR}/man.lib > ${WRKDIR}/man_tar
	cd ${PG_DIR}/man && ${TAR} -zxm -T ${WRKDIR}/man_tar  		\
		-f ${WRKSRC}/doc/man.tar.gz

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
