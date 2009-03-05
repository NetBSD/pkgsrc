# $NetBSD: Makefile,v 1.7 2009/03/05 20:58:37 joerg Exp $

PDO_DRIVER=		mysql
PDO_COMMENT=		MySQL
PDO_VERSION=		1.0.1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_PREFIX.mysql-client}

.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
