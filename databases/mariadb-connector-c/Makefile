# $NetBSD: Makefile,v 1.17 2021/05/13 11:46:13 nia Exp $

DISTNAME=	mariadb-connector-c-3.1.13-src
PKGNAME=	${DISTNAME:S/-src//g}
CATEGORIES=	databases
MASTER_SITES=	https://archive.mariadb.org/connector-c-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mariadb.com/kb/en/mariadb-connector-c/
COMMENT=	MariaDB Connector C library
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DWITH_EXTERNAL_ZLIB=ON

PKGCONFIG_OVERRIDE+=	mariadb_config/libmariadb.pc.in

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
