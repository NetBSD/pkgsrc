# $NetBSD: buildlink3.mk,v 1.2 2011/01/23 22:28:17 tnn Exp $

BUILDLINK_TREE+=	py-llab-astng

.if !defined(PY26_LOGILAB_ASTNG_BUILDLINK3_MK)
PY26_LOGILAB_ASTNG_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-llab-astng+= ${PYPKGPREFIX}-logilab-astng>=0.21.0
BUILDLINK_PKGSRCDIR.py-llab-astng?=	../../devel/py-logilab-astng

.endif	# PY26_LOGILAB_ASTNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-llab-astng
