# $NetBSD: buildlink3.mk,v 1.7 2018/01/07 13:04:16 rillig Exp $

BUILDLINK_TREE+=	py-imagingtk

.if !defined(PY_IMAGINGTK_BUILDLINK3_MK)
PY_IMAGINGTK_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

# guesstimate
BUILDLINK_API_DEPENDS.py-imagingtk+=	${PYPKGPREFIX}-imagingtk>=1.1.4
BUILDLINK_ABI_DEPENDS.py-imagingtk+=	${PYPKGPREFIX}-imagingtk>=1.1.7nb5
BUILDLINK_PKGSRCDIR.py-imagingtk?=	../../graphics/py-imagingtk

.include "../../graphics/py-imaging/buildlink3.mk"
.endif	# PY_IMAGINGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-imagingtk
