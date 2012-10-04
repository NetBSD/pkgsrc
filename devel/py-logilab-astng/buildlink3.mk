# $NetBSD: buildlink3.mk,v 1.3 2012/10/04 07:04:51 wiz Exp $

BUILDLINK_TREE+=	py-llab-astng

.if !defined(PY_LLAB_ASTNG_BUILDLINK3_MK)
PY_LLAB_ASTNG_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-llab-astng+= ${PYPKGPREFIX}-logilab-astng>=0.21.0
BUILDLINK_PKGSRCDIR.py-llab-astng?=	../../devel/py-logilab-astng

.endif	# PY_LLAB_ASTNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-llab-astng
