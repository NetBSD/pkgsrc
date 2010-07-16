# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/07/16 12:12:17 drochner Exp $

BUILDLINK_TREE+=	pynumexpr

.if !defined(PY_NUMEXPR_BUILDLINK3_MK)
PY_NUMEXPR_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pynumexpr+= ${PYPKGPREFIX}-numexpr>=1.3.1
BUILDLINK_PKGSRCDIR.pynumexpr?=	../../math/py-numexpr

.endif # PY_NUMEXPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-pynumexpr
