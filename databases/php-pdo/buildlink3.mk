# $NetBSD: buildlink3.mk,v 1.14 2025/02/08 03:10:22 taca Exp $

BUILDLINK_TREE+=	php-pdo

.if !defined(PHP_PDO_BUILDLINK3_MK)
PHP_PDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-pdo+=	${PHP_PKG_PREFIX}-pdo>=${PHP_BASE_VERS}
BUILDLINK_ABI_DEPENDS.php-pdo+=	${PHP_PKG_PREFIX}-pdo>=5.2.9
BUILDLINK_PKGSRCDIR.php-pdo?=	../../databases/php-pdo
BUILDLINK_INCDIRS.php-pdo?=	${PHP_INCDIR}/ext/pdo
.endif # PHP_PDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-pdo
