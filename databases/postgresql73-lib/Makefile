# $NetBSD: Makefile,v 1.10 2005/05/16 01:15:30 jlam Exp $

PKGNAME=		postgresql73-lib-${BASE_VERS}
PKGREVISION=		2
SVR4_PKGNAME=		pstgl
COMMENT=		PostgreSQL database headers and libraries

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../databases/postgresql73/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
BUILD_DIRS=		${WRKSRC}/src/include
BUILD_DIRS+=		${WRKSRC}/src/interfaces
BUILD_DIRS+=		${WRKSRC}/src/pl
PKGSRC_USE_TOOLS+=	gtar

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

INSTALLATION_DIRS=	man

.if ${OPSYS} == "FreeBSD"
PLIST_SUBST+=		LIBECPG="@comment "
PLIST_SUBST+=		LIBPQ="@comment "
.else
PLIST_SUBST+=		LIBECPG=
PLIST_SUBST+=		LIBPQ=
.endif

post-wrapper:
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

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
