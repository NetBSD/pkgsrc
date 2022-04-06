# $NetBSD: buildlink3.mk,v 1.1 2022/04/06 06:10:58 wiz Exp $

BUILDLINK_TREE+=	py-gi-docgen

.if !defined(PY_GI_DOCGEN_BUILDLINK3_MK)
PY_GI_DOCGEN_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gi-docgen+=	${PYPKGPREFIX}-gi-docgen>=2022.1
BUILDLINK_PKGSRCDIR.py-gi-docgen?=	../../devel/py-gi-docgen
BUILDLINK_DEPMETHOD.py-gi-docgen?=	build
.endif	# PY_GI_DOCGEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gi-docgen
