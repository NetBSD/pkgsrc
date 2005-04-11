# $NetBSD: Makefile,v 1.4 2005/04/11 20:34:43 recht Exp $

PKGNAME=		postgresql80-client-${BASE_VERS}
PKGREVISION=		# empty
COMMENT=		PostgreSQL database client programs

.include "../../databases/postgresql80/Makefile.common"

# XXX work around core dumps with the native libedit
USE_GNU_READLINE=	yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-readline

.include "../../mk/bsd.prefs.mk"

BUILD_DIRS=		${WRKSRC}/src/include
BUILD_DIRS+=		${WRKSRC}/src/interfaces
BUILD_DIRS+=		${WRKSRC}/src/bin
BUILD_DIRS+=		${WRKSRC}/doc

# without this the Darwin build fails
# (-bundle_loader related)
BUILD_DIRS+=		${WRKSRC}/src/backend

INSTALL_DIRS=		${WRKSRC}/src/bin
INSTALL_DIRS+=		${WRKSRC}/src/include
INSTALL_DIRS+=		${WRKSRC}/src/interfaces
INSTALL_DIRS+=		${WRKSRC}/doc

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

CONF_FILES=	${PG_DATA_DIR}/pg_service.conf.sample ${PKG_SYSCONFDIR}/pg_service.conf
CONF_FILES+=	${PG_DATA_DIR}/psqlrc.sample ${PKG_SYSCONFDIR}/psqlrc

post-buildlink:
#
# Avoid conflict between "${LOCALBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
#
.if (${OPSYS} == "SunOS")
	${TOUCH} ${BUILDLINK_DIR}/include/crypt.h
.endif

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/backend && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h

post-install:
	${INSTALL_DATA_DIR} ${PG_DOC_DIR}/TODO.detail
	cd ${WRKSRC}/doc; for file in					\
		FAQ* KNOWN_BUGS MISSING_FEATURES README.* TODO		\
		bug.template;						\
	do								\
		${INSTALL_DATA}	$${file} ${PG_DOC_DIR}/$${file};	\
	done
	cd ${WRKSRC}/doc/TODO.detail && \
		${PAX} -rwppm . ${PG_DOC_DIR}/TODO.detail

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
