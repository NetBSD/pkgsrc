# $NetBSD: buildlink3.mk,v 1.12 2018/01/07 13:03:54 rillig Exp $

BUILDLINK_TREE+=	cdparanoia

.if !defined(CDPARANOIA_BUILDLINK3_MK)
CDPARANOIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cdparanoia+=	cdparanoia>=3.0
BUILDLINK_ABI_DEPENDS.cdparanoia+=	cdparanoia>=3.0.9.8nb5
BUILDLINK_PKGSRCDIR.cdparanoia?=	../../audio/cdparanoia
.endif # CDPARANOIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cdparanoia
