# $NetBSD: buildlink3.mk,v 1.9 2010/08/22 20:48:18 markd Exp $

BUILDLINK_TREE+=	pycairo

.if !defined(PY_CAIRO_BUILDLINK3_MK)
PY_CAIRO_BUILDLINK3_MK:=

.  include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pycairo+=	${PYPKGPREFIX}-cairo>=1.0.2
BUILDLINK_ABI_DEPENDS.pycairo+=	${PYPKGPREFIX}-cairo>=1.8.8nb1
BUILDLINK_PKGSRCDIR.pycairo?=	../../graphics/py-cairo

.include "../../graphics/cairo/buildlink3.mk"
.endif # PY_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-pycairo
