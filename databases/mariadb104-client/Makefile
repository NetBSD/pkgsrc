# $NetBSD: Makefile,v 1.12 2023/04/19 08:09:25 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	6
COMMENT=	MariaDB 10.4, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON

INSTALL_DIRS+=	client include libmariadb man scripts

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
