# $NetBSD: buildlink3.mk,v 1.41 2023/11/15 13:00:02 jperkin Exp $

BUILDLINK_TREE+=	py-cairo

.if !defined(PY_CAIRO_BUILDLINK3_MK)
PY_CAIRO_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-cairo+=	${PYPKGPREFIX}-cairo>=1.10.0
.if ${PYVERSSUFFIX} == "2.7"
BUILDLINK_ABI_DEPENDS.py-cairo+=	${PYPKGPREFIX}-cairo>=1.18.2nb5
BUILDLINK_PKGSRCDIR.py-cairo?=		../../graphics/py-cairo118
.else
BUILDLINK_ABI_DEPENDS.py-cairo+=	${PYPKGPREFIX}-cairo>=1.24.0nb1
BUILDLINK_PKGSRCDIR.py-cairo?=		../../graphics/py-cairo
BUILDLINK_INCDIRS.py-cairo+=		${PYSITELIB}/cairo/include
.endif

.include "../../graphics/cairo/buildlink3.mk"
.endif	# PY_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cairo
