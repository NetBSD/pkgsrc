# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/11 20:42:34 drochner Exp $

BUILDLINK_TREE+=	py-llab-astng

.if !defined(PY26_LOGILAB_ASTNG_BUILDLINK3_MK)
PY26_LOGILAB_ASTNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-llab-astng+= ${PYPKGPREFIX}-logilab-astng>=0.21.0
BUILDLINK_PKGSRCDIR.py-llab-astng?=	../../devel/py-logilab-astng

.endif	# PY26_LOGILAB_ASTNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-llab-astng
