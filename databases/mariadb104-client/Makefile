# $NetBSD: Makefile,v 1.1 2021/05/08 19:47:16 jdolecek Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	MariaDB 10.4, a free SQL database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON

INSTALL_DIRS+=	client include libmariadb man scripts

.include "../../mk/bsd.pkg.mk"
