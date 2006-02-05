# $NetBSD: Makefile,v 1.4 2006/02/05 23:08:33 joerg Exp $

PDO_DRIVER=		mysql
PDO_COMMENT=		MySQL
PDO_VERSION=		1.0.1

PKGREVISION=		2

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
