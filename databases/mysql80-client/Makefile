# $NetBSD: Makefile,v 1.17 2024/08/25 06:18:30 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	2
COMMENT=	MySQL 8, a free SQL database (client)

CONFLICTS=	mysql3-client-[0-9]* mariadb-client-[0-9]*

.include "Makefile.common"

CMAKE_CONFIGURE_ARGS+=		-DWITHOUT_SERVER=ON
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
