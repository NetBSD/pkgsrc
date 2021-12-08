# $NetBSD: buildlink3.mk,v 1.17 2021/12/08 16:02:02 adam Exp $

BUILDLINK_TREE+=	pygobject

.if !defined(PY_GOBJECT_BUILDLINK3_MK)
PY_GOBJECT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.10.1nb1
BUILDLINK_ABI_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.28.7nb3
BUILDLINK_PKGSRCDIR.pygobject?=		../../devel/py-gobject

.include "../../devel/py-gobject-shared/buildlink3.mk"
.endif # PY_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pygobject
