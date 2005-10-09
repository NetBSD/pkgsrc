# $NetBSD: Makefile,v 1.1.1.1 2005/10/09 13:11:18 jdolecek Exp $

PDO_DRIVER=		sqlite
PDO_COMMENT=		SQLite v3

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/php-pdo/module.mk"
