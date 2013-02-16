# $NetBSD: buildlink3.mk,v 1.3 2013/02/16 12:07:26 wiz Exp $

BUILDLINK_TREE+=	py-imagingtk

.if !defined(PY_IMAGINGTK_BUILDLINK3_MK)
PY_IMAGINGTK_BUILDLINK3_MK:=
.include "../../lang/python/pyversion.mk"

# guesstimate
BUILDLINK_API_DEPENDS.py-imagingtk+=	${PYPKGPREFIX}-imagingtk>=1.1.4
BUILDLINK_ABI_DEPENDS.py-imagingtk+=	${PYPKGPREFIX}-imagingtk>=1.1.7nb3
BUILDLINK_PKGSRCDIR.py-imagingtk?=	../../graphics/py-imagingtk

.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.endif	# PY_IMAGINGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-imagingtk
