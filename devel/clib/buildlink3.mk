# $NetBSD: buildlink3.mk,v 1.2 2013/03/09 00:23:26 tonnerre Exp $

BUILDLINK_TREE+=	clib

.if !defined(CLIB_BUILDLINK3_MK)
CLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clib+=	clib>=0.3
BUILDLINK_ABI_DEPENDS.clib+=	clib>=0.3
BUILDLINK_PKGSRCDIR.clib?=	../../devel/clib
.endif # CLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-clib
