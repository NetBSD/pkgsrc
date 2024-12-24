# $NetBSD: Makefile,v 1.22 2024/12/24 18:52:22 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	MySQL 8, a free SQL database (client)

CONFLICTS=	mysql3-client-[0-9]* mariadb-client-[0-9]*

.include "Makefile.common"

CMAKE_CONFIGURE_ARGS+=		-DWITHOUT_SERVER=ON
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
