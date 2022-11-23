# $NetBSD: buildlink3.mk,v 1.14 2022/11/23 16:18:44 adam Exp $

BUILDLINK_TREE+=	${PYPKGPREFIX}-compizconfig

.if !defined(PY_COMPIZCONFIG_BUILDLINK3_MK)
PY_COMPIZCONFIG_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-compizconfig+=	${PYPKGPREFIX}-compizconfig>=0.6.0
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-compizconfig+=	${PYPKGPREFIX}-compizconfig>=0.8.4nb69
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-compizconfig?=	../../devel/py-compizconfig

.include "../../devel/libcompizconfig/buildlink3.mk"
.endif # PY_COMPIZCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PYPKGPREFIX}-compizconfig
