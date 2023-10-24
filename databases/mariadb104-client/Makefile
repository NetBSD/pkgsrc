# $NetBSD: Makefile,v 1.13 2023/10/24 22:08:28 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	7
COMMENT=	MariaDB 10.4, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON

INSTALL_DIRS+=	client include libmariadb man scripts

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
