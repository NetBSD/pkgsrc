# $NetBSD: buildlink3.mk,v 1.13 2015/12/06 14:10:22 taca Exp $

BUILDLINK_TREE+=	php-pdo

.if !defined(PHP_PDO_BUILDLINK3_MK)
PHP_PDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-pdo+=	${PHP_PKG_PREFIX}-pdo-${PKG_PHP_MAJOR_VERS}.*
BUILDLINK_ABI_DEPENDS.php-pdo+=	${PHP_PKG_PREFIX}-pdo>=5.2.9
BUILDLINK_PKGSRCDIR.php-pdo?=	../../databases/php-pdo
BUILDLINK_INCDIRS.php-pdo?=	include/php/ext/pdo
.endif # PHP_PDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-pdo
