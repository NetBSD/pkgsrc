# $NetBSD: Makefile,v 1.6 2021/07/24 11:49:44 nia Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	MariaDB 10.4, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON

INSTALL_DIRS+=	client include libmariadb man scripts

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
