# $NetBSD: Makefile,v 1.2 2005/12/03 17:24:28 jdolecek Exp $

PDO_DRIVER=		dblib
PDO_COMMENT=		FreeTDS/Sybase/MS SQL
PDO_VERSION=		1.0

.include "../../databases/php-pdo/module.mk"

CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_DIR}/freetds

# requires 0.63 version to compile, doesn't compile with 0.61
BUILDLINK_DEPENDS.freetds+=	freetds>=0.63

.include "../../databases/freetds/buildlink3.mk"
.include "../../databases/php-pdo/buildlink3.mk"
