# $NetBSD: buildlink3.mk,v 1.22 2024/09/21 10:24:28 wiz Exp $

BUILDLINK_TREE+=	${PYPKGPREFIX}-compizconfig

.if !defined(PY_COMPIZCONFIG_BUILDLINK3_MK)
PY_COMPIZCONFIG_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-compizconfig+=	${PYPKGPREFIX}-compizconfig>=0.6.0
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-compizconfig+=	${PYPKGPREFIX}-compizconfig>=0.8.4nb81
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-compizconfig?=	../../devel/py-compizconfig

.include "../../devel/libcompizconfig/buildlink3.mk"
.endif # PY_COMPIZCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PYPKGPREFIX}-compizconfig
