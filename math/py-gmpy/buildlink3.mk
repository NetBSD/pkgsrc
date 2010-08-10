# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/08/10 17:59:00 drochner Exp $

BUILDLINK_TREE+=	py26-gmpy

.if !defined(PY26_GMPY_BUILDLINK3_MK)
PY26_GMPY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-gmpy+=	${PYPKGPREFIX}-gmpy>=1.12
BUILDLINK_PKGSRCDIR.py26-gmpy?=	../../math/py-gmpy

.endif	# PY26_GMPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-gmpy
