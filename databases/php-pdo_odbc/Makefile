# $NetBSD: Makefile,v 1.2 2005/12/03 17:24:28 jdolecek Exp $

PDO_DRIVER=		odbc
PDO_COMMENT=		ODBC
PDO_VERSION=		1.0

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=unixodbc,${BUILDLINK_PREFIX.unixodbc}

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
