# $NetBSD: Makefile,v 1.18 2018/12/13 19:51:45 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	1
COMMENT=	MySQL 5, a free SQL database (client)

CONFLICTS=	mysql3-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=		-DWITHOUT_SERVER=ON
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes
INSTALL_DIRS+=		client include libmysql man scripts testclients

.include "../../mk/bsd.pkg.mk"
