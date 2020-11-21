# $NetBSD: buildlink3.mk,v 1.1 2020/11/21 13:49:50 otis Exp $

BUILDLINK_TREE+=	php-psr

.if !defined(PHP_PSR_BUILDLINK3_MK)
PHP_PSR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-psr+=		${PHP_PKG_PREFIX}-psr>=1.0.0
BUILDLINK_PKGSRCDIR.php-psr?=		../../devel/php-psr
.endif	# PHP_PSR_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-psr
