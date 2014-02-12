# $NetBSD: buildlink3.mk,v 1.6 2014/02/12 00:57:25 prlw1 Exp $

BUILDLINK_TREE+=	py-gobject3

.if !defined(PY_GOBJECT3_BUILDLINK3_MK)
PY_GOBJECT3_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gobject3+=	${PYPKGPREFIX}-gobject3>=3.2.2
BUILDLINK_ABI_DEPENDS.py-gobject3?=	${PYPKGPREFIX}-gobject3>=3.4.0
BUILDLINK_PKGSRCDIR.py-gobject3?=	../../devel/py-gobject3

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.endif	# PY_GOBJECT3_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gobject3
