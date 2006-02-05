# $NetBSD: Makefile,v 1.3 2006/02/05 23:08:33 joerg Exp $

PDO_DRIVER=		odbc
PDO_COMMENT=		ODBC
PDO_VERSION=		1.0
PKGREVISION=		1

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=unixodbc,${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
