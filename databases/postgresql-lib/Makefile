# $NetBSD: Makefile,v 1.7 2002/10/19 03:03:50 jlam Exp $

PKGNAME=		postgresql-lib-${BASE_VERS}
COMMENT=		PostgreSQL database headers and libraries

USE_BUILDLINK2=		# defined

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
BUILD_DIRS=		${WRKSRC}/src/include
BUILD_DIRS+=		${WRKSRC}/src/interfaces
BUILD_DIRS+=		${WRKSRC}/src/pl

.include "../../mk/bsd.prefs.mk"

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
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz             \
		`${SED} -e "s|^#.*||" ${FILESDIR}/man.lib`

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
