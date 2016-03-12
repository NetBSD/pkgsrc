# $NetBSD: buildlink3.mk,v 1.2 2016/03/12 08:33:12 fhajny Exp $

.include "../../lang/php/phpversion.mk"

BUILDLINK_TREE+=	${PHP_PKG_PREFIX}-raphf

.if !defined(${PHP_PKG_PREFIX}_RAPHF_BUILDLINK3_MK)
${PHP_PKG_PREFIX}_RAPHF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.${PHP_PKG_PREFIX}-raphf+=	${PHP_PKG_PREFIX}-raphf>=1.0.4nb1<2
BUILDLINK_PKGSRCDIR.${PHP_PKG_PREFIX}-raphf?=	../../devel/php-raphf
.endif	# ${PHP_PKG_PREFIX}_RAPHF_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PHP_PKG_PREFIX}-raphf
