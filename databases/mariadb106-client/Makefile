# $NetBSD: Makefile,v 1.10 2022/11/27 20:05:52 nia Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	MariaDB 10.6, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON

INSTALL_DIRS+=	client include libmariadb man scripts

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
