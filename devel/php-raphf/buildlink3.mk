# $NetBSD: buildlink3.mk,v 1.3 2025/09/23 15:41:34 taca Exp $

BUILDLINK_TREE+=	php-raphf

.if !defined(PHP_RAPHF_BUILDLINK3_MK)
PHP_RAPHF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-raphf+=	${PHP_PKG_PREFIX}-raphf>=1.0.4nb1<2
BUILDLINK_PKGSRCDIR.php-raphf?=		../../devel/php-raphf

.endif	# PHP_RAPHF_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-raphf
