# $NetBSD: Makefile,v 1.27 2012/09/15 15:03:22 obache Exp $

DISTNAME=	mysql-connector-odbc-5.1.8
PKGNAME=	${DISTNAME:S/mysql-connector-odbc/myodbc/}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-ODBC/5.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mysql.com/
COMMENT=	ODBC driver (server side) for MySQL
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--disable-myodbc3i
CONFIGURE_ARGS+=	--disable-test
CONFIGURE_ARGS+=	--with-mysql-path=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--without-samples

INSTALLATION_DIRS=	share/doc/mysql-connector-odbc

.include "options.mk"

# 5.5 fails on my_free(), which no longer accepts 2 arguments, but 1
MYSQL_VERSIONS_ACCEPTED=	51 50

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
