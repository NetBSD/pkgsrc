# $NetBSD: buildlink3.mk,v 1.1 2023/10/16 12:55:56 ryoon Exp $

BUILDLINK_TREE+=	pystring

.if !defined(PYSTRING_BUILDLINK3_MK)
PYSTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pystring+=	pystring>=1.1.4
BUILDLINK_PKGSRCDIR.pystring?=		../../devel/pystring
.endif	# PYSTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-pystring
