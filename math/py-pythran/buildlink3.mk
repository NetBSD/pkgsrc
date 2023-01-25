# $NetBSD: buildlink3.mk,v 1.2 2023/01/25 09:06:54 adam Exp $

BUILDLINK_TREE+=	py-pythran

.if !defined(PY_PYTHRAN_BUILDLINK3_MK)
PY_PYTHRAN_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.py-pythran+=	${PYPKGPREFIX}-pythran>=0.10.0
BUILDLINK_PKGSRCDIR.py-pythran?=	../../math/py-pythran
BUILDLINK_DEPMETHOD.py-pythran?=	build

BUILDLINK_CONTENTS_FILTER.py-pythran=	${EGREP} '(\.h$$|\.hpp$$)'
.endif	# PY_PYTHRAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pythran
