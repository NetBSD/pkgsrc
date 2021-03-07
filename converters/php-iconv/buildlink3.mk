# $NetBSD: buildlink3.mk,v 1.2 2021/03/07 08:06:18 taca Exp $

.include "../../lang/php/phpversion.mk"

BUILDLINK_TREE+=	${PHP_PKG_PREFIX}-iconv

.if !defined(${PHP_PKG_PREFIX:tu}_ICONV_BUILDLINK3_MK)
${PHP_PKG_PREFIX:tu}_ICONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.${PHP_PKG_PREFIX}-iconv+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}
BUILDLINK_PKGSRCDIR.${PHP_PKG_PREFIX}-iconv?=	../../converters/php-iconv

.endif	# ${PHP_PKG_PREFIX:tu}_ICONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PHP_PKG_PREFIX}-iconv
