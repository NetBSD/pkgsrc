# $NetBSD: buildlink3.mk,v 1.2 2017/12/09 02:28:19 taca Exp $

.include "../../lang/php/phpversion.mk"

BUILDLINK_TREE+=	${PHP_PKG_PREFIX}-raphf

.if !defined(${PHP_PKG_PREFIX}_RAPHF_BUILDLINK3_MK)
${PHP_PKG_PREFIX}_RAPHF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.${PHP_PKG_PREFIX}-raphf+=	${PHP_PKG_PREFIX}-raphf>=2.0.0
BUILDLINK_PKGSRCDIR.${PHP_PKG_PREFIX}-raphf?=	../../devel/php-raphf2
.endif	# ${PHP_PKG_PREFIX}_RAPHF_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PHP_PKG_PREFIX}-raphf
