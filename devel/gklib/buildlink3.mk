# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 13:21:40 ryoon Exp $

BUILDLINK_TREE+=	gklib

.if !defined(GKLIB_BUILDLINK3_MK)
GKLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gklib+=	gklib>=0.0.1
BUILDLINK_PKGSRCDIR.gklib?=	../../devel/gklib
.endif	# GKLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-gklib
