# $NetBSD: json.mk,v 1.1 2021/03/07 13:20:56 taca Exp $

#
# Suport for dependency to php-json which contains base php package
# from PHP 8.0 and later.
#

.if !defined(PHP_JSON_MK)
PHP_JSON_MK:=	# empty

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_MAJOR_VERS} < 8
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json
.else
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.endif

.endif	# PHP_JSON_MK
