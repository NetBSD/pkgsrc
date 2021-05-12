# $NetBSD: Makefile,v 1.3 2021/05/12 11:20:29 nia Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	2
COMMENT=	MariaDB 10.4, a free SQL database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON

INSTALL_DIRS+=	client include libmariadb man scripts

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
