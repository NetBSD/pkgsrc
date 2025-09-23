# $NetBSD: buildlink3.mk,v 1.3 2025/09/23 15:41:54 taca Exp $

BUILDLINK_TREE+=	php-raphf

.if !defined(PHP_RAPHF_BUILDLINK3_MK)
PHP_RAPHF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-raphf+=	${PHP_PKG_PREFIX}-raphf>=2.0.0
BUILDLINK_PKGSRCDIR.php-raphf?=		../../devel/php-raphf2

.endif	# PHP_RAPHF_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-raphf
