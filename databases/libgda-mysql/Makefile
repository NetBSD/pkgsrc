# $NetBSD: Makefile,v 1.36 2026/01/07 08:46:10 wiz Exp $

LIBGDA_PROVIDER=	mysql

PKGREVISION= 19
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
