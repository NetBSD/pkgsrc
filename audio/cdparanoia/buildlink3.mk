# $NetBSD: buildlink3.mk,v 1.11 2012/05/07 01:53:13 dholland Exp $

BUILDLINK_TREE+=	cdparanoia

.if !defined(CDPARANOIA_BUILDLINK3_MK)
CDPARANOIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cdparanoia+=		cdparanoia>=3.0
BUILDLINK_ABI_DEPENDS.cdparanoia+=	cdparanoia>=3.0.9.8nb5
BUILDLINK_PKGSRCDIR.cdparanoia?=	../../audio/cdparanoia
.endif # CDPARANOIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-cdparanoia
