# $NetBSD: Makefile,v 1.16 2026/05/14 16:40:34 ryoon Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
PKGREVISION=	3
COMMENT=	MariaDB 11.4, a free MySQL compatible database (client)

CONFLICTS=	mysql-client-[0-9]*

.include "Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DWITHOUT_SERVER=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_WSREP=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBFMT=system

INSTALL_DIRS+=	client include libmariadb man scripts

CMAKE_CONFIGURE_ARGS.NetBSD+=	-DTGOTOLIB=-ltermcap

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
