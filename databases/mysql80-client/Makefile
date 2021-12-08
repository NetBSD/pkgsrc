# $NetBSD: Makefile,v 1.3 2021/12/08 16:03:40 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	2
COMMENT=	MySQL 8, a free SQL database (client)

CONFLICTS=	mysql3-client-[0-9]* mariadb-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=		-DWITHOUT_SERVER=ON
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes
INSTALL_DIRS+=		client include libmysql man scripts testclients

.include "../../mk/bsd.pkg.mk"
