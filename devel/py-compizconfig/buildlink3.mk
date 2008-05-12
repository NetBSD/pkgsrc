# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/05/12 11:20:58 jmcneill Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_COMPIZCONFIG_BUILDLINK3_MK:=	${PY_COMPIZCONFIG_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	${PYPKGPREFIX}-compizconfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:N${PYPKGPREFIX}-compizconfig}
BUILDLINK_PACKAGES+=	${PYPKGPREFIX}-compizconfig
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}${PYPKGPREFIX}-compizconfig

.if !empty(PY_COMPIZCONFIG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-compizconfig+=	${PYPKGPREFIX}-compizconfig>=0.6.0
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-compizconfig?=	${PYPKGPREFIX}-compizconfig>=0.6.0
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-compizconfig?=	../../devel/py-compizconfig

.include "../../devel/libcompizconfig/buildlink3.mk"

.endif	# PY_COMPIZCONFIG_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
