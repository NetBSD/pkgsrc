# $NetBSD: Makefile,v 1.4 2006/06/02 18:27:55 joerg Exp $

PDO_DRIVER=		sqlite
PDO_COMMENT=		SQLite v3
PDO_VERSION=		1.0

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
