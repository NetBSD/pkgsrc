# $NetBSD: Makefile,v 1.20 2019/02/05 20:19:55 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	MySQL 5, a free SQL database (client)

CONFLICTS=	mysql3-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=		-DWITHOUT_SERVER=ON
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes
INSTALL_DIRS+=		client include libmysql man scripts testclients

.include "../../mk/bsd.pkg.mk"
