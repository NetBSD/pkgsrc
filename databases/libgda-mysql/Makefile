# $NetBSD: Makefile,v 1.39 2026/09/29 06:04:12 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 22
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
