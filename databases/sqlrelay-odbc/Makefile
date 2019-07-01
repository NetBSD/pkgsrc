# $NetBSD: Makefile,v 1.18 2019/07/01 04:08:02 ryoon Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-odbc/}
PKGREVISION=		7
COMMENT=		ODBC support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		gnu-lgpl-v2

CONFIGURE_ARGS+=	--with-odbc-prefix=${BUILDLINK_PREFIX.unixodbc}
CONFIGURE_ARGS+=        --disable-postgresql
CONFIGURE_ARGS+=        --disable-sqlite
CONFIGURE_ARGS+=        --disable-freetds
CONFIGURE_ARGS+=        --disable-mysql

BUILD_DIRS=             src/connections

INSTALLATION_DIRS+=     libexec/sqlrelay

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${BUILD_DIRS}/sqlrconnection_odbc.la \
		${DESTDIR}${PREFIX}/libexec/sqlrelay

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
