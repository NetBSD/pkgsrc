# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:46 joerg Exp $

BUILDLINK_TREE+=	hamlib

.if !defined(HAMLIB_BUILDLINK3_MK)
HAMLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hamlib+=	hamlib>=1.1.4
BUILDLINK_ABI_DEPENDS.hamlib+=	hamlib>=1.2.5
BUILDLINK_PKGSRCDIR.hamlib?=	../../ham/hamlib
.endif # HAMLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hamlib
