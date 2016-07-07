# $NetBSD: buildlink3.mk,v 1.1 2016/07/07 13:59:00 jperkin Exp $

BUILDLINK_TREE+=	php-mbstring

.if !defined(PHP_MBSTRING_BUILDLINK3_MK)
PHP_MBSTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php-mbstring+=	${PHP_PKG_PREFIX}-mbstring>0
BUILDLINK_PKGSRCDIR.php-mbstring?=	../../converters/php-mbstring
BUILDLINK_DEPMETHOD.php-mbstring?=	build
.endif	# PHP_MBSTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-php-mbstring
