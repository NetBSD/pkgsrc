# $NetBSD: Makefile,v 1.6 2009/03/05 20:58:37 joerg Exp $

PDO_DRIVER=		odbc
PDO_COMMENT=		ODBC
PDO_VERSION=		1.0

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=unixodbc,${BUILDLINK_PREFIX.unixodbc}

BROKEN=		module kills Apache1 or CLI PHP on startup due to threaded unixodbc

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
