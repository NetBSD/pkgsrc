# $NetBSD: json.mk,v 1.2 2025/02/08 02:56:24 taca Exp $

#
# Suport for dependency to php-json which contains base php package
# from PHP 8.0 and later.
#
# There is no need to include this file if a package is not supported
# by PHP 8 and later.
#

.if !defined(PHP_JSON_MK)
PHP_JSON_MK:=	# empty

.include "../../lang/php/phpversion.mk"

.if ${PHP_VER} < 80
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json

.include "../../textproc/php-json/buildlink3.mk"
.else
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.endif

.endif	# PHP_JSON_MK
