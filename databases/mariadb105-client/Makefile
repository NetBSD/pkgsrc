# $NetBSD: Makefile,v 1.7 2021/10/21 07:46:33 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	3
COMMENT=	MariaDB 10.5, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON

INSTALL_DIRS+=	client include libmariadb man scripts

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
