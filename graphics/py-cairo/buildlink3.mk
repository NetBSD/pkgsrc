# $NetBSD: buildlink3.mk,v 1.32 2022/11/28 18:12:15 adam Exp $

BUILDLINK_TREE+=	py-cairo

.if !defined(PY_CAIRO_BUILDLINK3_MK)
PY_CAIRO_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-cairo+=	${PYPKGPREFIX}-cairo>=1.10.0
BUILDLINK_ABI_DEPENDS.py-cairo+=	${PYPKGPREFIX}-cairo>=1.18.2nb1
.if ${PYVERSSUFFIX} == "2.7"
BUILDLINK_PKGSRCDIR.py-cairo?=		../../graphics/py-cairo118
.else
BUILDLINK_PKGSRCDIR.py-cairo?=		../../graphics/py-cairo
.endif

.include "../../graphics/cairo/buildlink3.mk"
.endif	# PY_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cairo
