# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/27 23:52:53 tonnerre Exp $

BUILDLINK_TREE+=	clib

.if !defined(CLIB_BUILDLINK3_MK)
CLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clib+=	clib>=0.2
BUILDLINK_ABI_DEPENDS.clib+=	clib>=0.2
BUILDLINK_PKGSRCDIR.clib?=	../../devel/clib
.endif # CLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-clib
