# $NetBSD: buildlink3.mk,v 1.11 2012/03/03 00:11:56 wiz Exp $

BUILDLINK_TREE+=	pygobject

.if !defined(PY_GOBJECT_BUILDLINK3_MK)
PY_GOBJECT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.10.1nb1
BUILDLINK_ABI_DEPENDS.pygobject?=	${PYPKGPREFIX}-gobject>=2.28.6nb3
BUILDLINK_PKGSRCDIR.pygobject?=	../../devel/py-gobject

.include "../../devel/py-gobject-shared/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # PY_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pygobject
