# $NetBSD: buildlink3.mk,v 1.1 2014/02/12 00:57:25 prlw1 Exp $

BUILDLINK_TREE+=	py-gobject3-common

.if !defined(PY_GOBJECT3_COMMON_BUILDLINK3_MK)
PY_GOBJECT3_COMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-gobject3-common+=	py-gobject3-common>=3.10.2
BUILDLINK_PKGSRCDIR.py-gobject3-common?=	../../devel/py-gobject3-common
BUILDLINK_DEPMETHOD.py-gobject3-common?=	build

.endif	# PY_GOBJECT3_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gobject3-common
