# $NetBSD: Makefile,v 1.4 2024/01/23 09:52:05 nia Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	MariaDB 10.11, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON

INSTALL_DIRS+=	client include libmariadb man scripts

CMAKE_ARGS.NetBSD+=	-DTGOTOLIB=-ltermcap

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
