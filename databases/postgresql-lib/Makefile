# $NetBSD: Makefile,v 1.14 2004/01/21 08:14:29 jlam Exp $

PKGNAME=		postgresql-lib-${BASE_VERS}
PKGREVISION=		1
SVR4_PKGNAME=		pstgl
COMMENT=		PostgreSQL database headers and libraries

USE_BUILDLINK2=		yes

.include "../../databases/postgresql/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
BUILD_DIRS=		${WRKSRC}/src/include
BUILD_DIRS+=		${WRKSRC}/src/interfaces
BUILD_DIRS+=		${WRKSRC}/src/pl

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

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
