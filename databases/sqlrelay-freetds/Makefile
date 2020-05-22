# $NetBSD: Makefile,v 1.28 2020/05/22 10:56:02 adam Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-freetds/}
PKGREVISION=		16
COMMENT=		FreeTDS support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--with-freetds-prefix=${BUILDLINK_PREFIX.freetds}
CONFIGURE_ARGS+=	--disable-postgresql
CONFIGURE_ARGS+=	--disable-sqlite
CONFIGURE_ARGS+=	--disable-mysql
CONFIGURE_ARGS+=	--disable-odbc

BUILD_DIRS=		src/connections

INSTALLATION_DIRS+=	libexec/sqlrelay

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${BUILD_DIRS}/sqlrconnection_freetds.la \
		${DESTDIR}${PREFIX}/libexec/sqlrelay

.include "../../databases/freetds/buildlink3.mk"
.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
