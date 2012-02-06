# $NetBSD: buildlink3.mk,v 1.10 2012/02/06 12:40:33 wiz Exp $
#

BUILDLINK_TREE+=	py-clutter

.if !defined(PY_CLUTTER_BUILDLINK3_MK)
PY_CLUTTER_BUILDLINK3_MK:=

.  include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-clutter+=	${PYPKGPREFIX}-clutter>=1.0.0
BUILDLINK_ABI_DEPENDS.py-clutter?=	${PYPKGPREFIX}-clutter>=1.0.2nb8
BUILDLINK_PKGSRCDIR.py-clutter?=	../../graphics/py-clutter

.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.endif	# PY_CLUTTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-clutter
