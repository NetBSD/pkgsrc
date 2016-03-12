# $NetBSD: buildlink3.mk,v 1.1 2016/03/12 09:11:01 fhajny Exp $

.include "../../lang/php/phpversion.mk"

BUILDLINK_TREE+=	${PHP_PKG_PREFIX}-raphf

.if !defined(${PHP_PKG_PREFIX}_RAPHF_BUILDLINK3_MK)
${PHP_PKG_PREFIX}_RAPHF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.${PHP_PKG_PREFIX}-raphf+=	${PHP_PKG_PREFIX}-raphf>=2.0.0
BUILDLINK_PKGSRCDIR.${PHP_PKG_PREFIX}-raphf?=	../../devel/php-raphf
.endif	# ${PHP_PKG_PREFIX}_RAPHF_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PHP_PKG_PREFIX}-raphf
