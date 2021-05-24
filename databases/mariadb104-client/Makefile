# $NetBSD: Makefile,v 1.5 2021/05/24 19:49:29 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	3
COMMENT=	MariaDB 10.4, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON

INSTALL_DIRS+=	client include libmariadb man scripts

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
