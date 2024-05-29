# $NetBSD: Makefile,v 1.9 2024/05/29 16:31:42 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	1
COMMENT=	MariaDB 10.11, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_ARGS+=	-DWITHOUT_SERVER=ON
CMAKE_ARGS+=	-DWITH_LIBFMT=system

INSTALL_DIRS+=	client include libmariadb man scripts

CMAKE_ARGS.NetBSD+=	-DTGOTOLIB=-ltermcap

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
