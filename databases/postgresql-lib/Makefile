# $NetBSD: Makefile,v 1.5 2002/04/04 07:41:02 jlam Exp $

PKGNAME=		postgresql-lib-${BASE_VERS}
COMMENT=		PostgreSQL database headers and libraries

USE_BUILDLINK_ONLY=	YES

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_DIR}
DIRS_TO_BUILD=		src/include src/interfaces src/pl

.include "../../mk/bsd.prefs.mk"

do-build:
#
# Avoid conflict between "${LOCALBASE}/include/openssl/des.h" and
# "/usr/include/crypt.h" -- we want the definitions in the former.
#
.if (${OPSYS} == "SunOS")
	${TOUCH} ${BUILDLINK_DIR}/include/crypt.h
.endif
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${DIRS_TO_BUILD}
	cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${INSTALL_TARGET}
.endfor
	cd ${WRKSRC}/src/include && ${SETENV} ${MAKE_ENV}		\
		${MAKE_PROGRAM} install-all-headers

post-install:
	${GTAR} zxCf ${PREFIX}/man ${WRKSRC}/doc/man.tar.gz             \
		`${SED} -e "s|^#.*||" ${FILESDIR}/man.lib`

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
