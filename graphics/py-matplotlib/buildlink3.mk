# $NetBSD: buildlink3.mk,v 1.7 2017/05/29 20:59:21 adam Exp $

BUILDLINK_TREE+=	pymatplotlib

.if !defined(PYMATPLOTLIB_BUILDLINK3_MK)
PYMATPLOTLIB_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pymatplotlib+=	${PYPKGPREFIX}-matplotlib>=0.87.2
BUILDLINK_PKGSRCDIR.pymatplotlib?=	../../graphics/py-matplotlib

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.endif # PYMATPLOTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pymatplotlib
