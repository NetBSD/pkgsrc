# $NetBSD: buildlink3.mk,v 1.1 2012/11/03 13:55:16 imil Exp $

BUILDLINK_TREE+=	py-hgtools

.if !defined(PY_HGTOOLS_BUILDLINK3_MK)
PY_HGTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-hgtools+=	${PYPKGPREFIX}-hgtools>=2.0.2
BUILDLINK_PKGSRCDIR.py-hgtools?=	../../devel/py-hgtools
.endif	# PY_HGTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-hgtools
