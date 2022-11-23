# $NetBSD: Makefile,v 1.8 2022/11/23 16:19:36 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	1
COMMENT=	MySQL 8, a free SQL database (client)

CONFLICTS=	mysql3-client-[0-9]* mariadb-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=		-DWITHOUT_SERVER=ON
UNWRAP_FILES+=		scripts/mysql_config
INFO_FILES=		yes
.for dir in client include libmysql man scripts testclients
INSTALL_DIRS+=		${WRKDIR}/build/${dir}
.endfor

.include "../../mk/bsd.pkg.mk"
