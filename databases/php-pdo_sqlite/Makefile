# $NetBSD: Makefile,v 1.6 2009/03/05 20:58:37 joerg Exp $

PDO_DRIVER=		sqlite
PDO_COMMENT=		SQLite v3
PDO_VERSION=		1.0

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
