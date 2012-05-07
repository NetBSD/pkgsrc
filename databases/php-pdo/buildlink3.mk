# $NetBSD: buildlink3.mk,v 1.12 2012/05/07 01:53:18 dholland Exp $

BUILDLINK_TREE+=	php-pdo

.if !defined(PHP_PDO_BUILDLINK3_MK)
PHP_PDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-pdo+=	${PHP_PKG_PREFIX}-pdo-5.*
BUILDLINK_ABI_DEPENDS.php-pdo+=	${PHP_PKG_PREFIX}-pdo>=5.2.9
BUILDLINK_PKGSRCDIR.php-pdo?=	../../databases/php-pdo
BUILDLINK_INCDIRS.php-pdo?=	include/php/ext/pdo
.endif # PHP_PDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-pdo
