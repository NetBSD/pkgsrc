# $NetBSD: Makefile,v 1.3 2004/04/25 23:14:40 seb Exp $

PKGNAME=		postgresql-lib-${BASE_VERS}
PKGREVISION=		1
SVR4_PKGNAME=		pstgl
COMMENT=		PostgreSQL database headers and libraries

.include "../../databases/postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

BUILD_DIRS=		${WRKSRC}/src/include
BUILD_DIRS+=		${WRKSRC}/src/interfaces
BUILD_DIRS+=		${WRKSRC}/src/pl

.include "../../mk/bsd.prefs.mk"

# As told by Josh Berkus
# currently broken for SunOS, will be fixed in 7.4.3
.if (${OPSYS} != "SunOS")
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

post-install:
	cd ${WRKSRC}/src/include && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} install-all-headers
	${EGREP} -v "^#" ${FILESDIR}/man.lib > ${WRKDIR}/man_tar
	cd ${PREFIX}/man && ${TAR} -zxm -T ${WRKDIR}/man_tar  		\
		-f ${WRKSRC}/doc/man.tar.gz

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
